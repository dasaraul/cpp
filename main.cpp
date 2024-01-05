#include <cstdlib>
#include "Oxorany/oxorany.h"
#include "KittyMemory/obfuscate.h"
#include "KittyMemory/MemoryPatch.h"
#include "KittyMemory/KittyScanner.h"
#include "MemoryTools.h"
#include "curl/curl.h"
#include "Tools.h"
#include "json.hpp"
#include "Includes.h"
#include <libzip/zip.h>
#include <fstream>
#include <sstream>
#include <sys/system_properties.h>

using namespace std;

using json = nlohmann::ordered_json;
bool bValid = false, lolo = false;
std::string g_Token, g_Auth;

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *) userp;

    mem->memory = (char *) realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}
std::string Login(const char *user_key) {
   
    char build_id[64] = {0};
    __system_property_get(OBFUSCATE("ro.build.display.id"), build_id);
    char build_hardware[64] = {0};
    __system_property_get(OBFUSCATE("ro.hardware"), build_hardware);

    std::string bKeyID;
    bKeyID.reserve(128);
   
    bKeyID += build_id;
    bKeyID += build_hardware;
    if (!bKeyID.empty()) {
        size_t pos = bKeyID.find(' ');
        while (pos != std::string::npos) {
            bKeyID.replace(pos, 1, "");
            pos = bKeyID.find(' ', pos);
        }
    }

    std::string UUID = bKeyID;

    std::string errMsg;

    struct MemoryStruct chunk{};
    chunk.memory = (char *) malloc(1);
    chunk.size = 0;

    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        char lol[100];
        sprintf(lol,OBFUSCATE("https://nusantarahax.com/login/connect"));
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, lol);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Accept: application/json");
        headers = curl_slist_append(headers,"Content-Type: application/x-www-form-urlencoded");
        headers = curl_slist_append(headers, "Charset: UTF-8");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        char data[4096];
        sprintf(data, "game=PUBG&user_key=%s&serial=%s", user_key, UUID.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYSTATUS, 0);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "AbsoluteX/2.0");
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            try {
                json result = json::parse(chunk.memory);
                auto STATUS = std::string{"status"};
                if (result[STATUS] == true) {
                    auto DATA = std::string{"data"};
                    auto TOKEN = std::string{"token"};
                    auto RNG = std::string{"rng"};
                    std::string token = result[DATA][TOKEN].get<std::string>();
                    time_t rng = result[DATA][RNG].get<time_t>();
                    if (rng + 30 > time(0)) {
                        std::string auth = "PUBG";
                        auth += "-";
                        auth += user_key;
                        auth += "-";
                        auth += UUID;
                        auth += "-";
                        auth += "Vm8Lk7Uj2JmsjCPVPVjrLa7zgfx3uz9E";
                        std::string outputAuth = Tools::CalcMD5(auth);
                        g_Token = token;
                        g_Auth = outputAuth;
                        bValid = g_Token == g_Auth;
                        lolo = true;
                        if (bValid && lolo) {
                            printf("Login Success \n");
                        }
                    }
                } else {
                    auto REASON = std::string{"reason"};
                    errMsg = result[REASON].get<std::string>();
                }
            } catch (json::exception &e) {
                errMsg = e.what();
            }
        } else {
            errMsg = curl_easy_strerror(res);
        }
    }
    curl_easy_cleanup(curl);
    return bValid ? "OK" : errMsg.c_str();
}


void doPatch(uintptr_t offset, string replace) {
    MemoryPatch::createWithHex(oxorany("libUE4.so"), offset, std::move(replace)).Modify();
}

void doBypass(uintptr_t offset, string replace) {
    MemoryPatch::createWithHex(oxorany("libanogs.so"), offset, std::move(replace)).Modify();
}

void doBypassCrashSight(uintptr_t offset, string replace) {
    MemoryPatch::createWithHex(oxorany("libCrashSight.so"), offset, std::move(replace)).Modify();
}

int main(int argc, char *argv[]) {
    FILE *fp;
    ProcMap il2cppMap;
    auto game = string(argv[2]);
    KittyMemory::getPid(std::string(game).c_str());
    
    static std::string err;
    err = Login(argv[1]);
    if (!err.empty() && err != "OK") {
       printf("Error: %s\n", err.c_str());
	   exit(-1);
    }

   do {
                        il2cppMap = KittyMemory::getLibraryMap(oxorany("libUE4.so"));
                    } while (!il2cppMap.isValid());
					doPatch(oxorany(0xa96a790), oxorany("00 00 80 D2 C0 03 5F D6"));
					doPatch(oxorany(0xa96a240), oxorany("00 00 80 D2 C0 03 5F D6"));
					doPatch(oxorany(0xa96a3f0), oxorany("00 00 80 D2 C0 03 5F D6"));
					doPatch(oxorany(0xa96a960), oxorany("00 00 80 D2 C0 03 5F D6"));
                    doPatch(oxorany(0xa96a3c0), oxorany("00 00 80 D2 C0 03 5F D6"));
					doPatch(oxorany(0xa96a5d0), oxorany("00 00 80 D2 C0 03 5F D6"));
					doPatch(oxorany(0xa96a2e0), oxorany("00 00 80 D2 C0 03 5F D6"));
					doPatch(oxorany(0xa96a7d0), oxorany("00 00 80 D2 C0 03 5F D6"));
					doPatch(oxorany(0xa969200), oxorany("00 00 80 D2 C0 03 5F D6"));
					doPatch(oxorany(0xa969240), oxorany("00 00 80 D2 C0 03 5F D6"));
   do {
                        il2cppMap = KittyMemory::getLibraryMap(oxorany("libanogs.so"));
                    } while (!il2cppMap.isValid());
					doBypass(oxorany(0xc54e0), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0xc5500), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0xc54f0), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0xc5520), oxorany("00 00 80 D2 C0 03 5F D6"));
                    doBypass(oxorany(0xc5480), oxorany("00 00 80 D2 C0 03 5F D6"));
                    doBypass(oxorany(0xc5470), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0xc5580), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0xc54a0), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0xc5510), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0xc55f0), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0xc5610), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0xc5650), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0xc5cb0), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0xc5e10), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0xc56c0), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0xc5780), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0xc5870), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0xc5920), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0x4afd10), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0x4afd20), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0x4afd30), oxorany("00 00 80 D2 C0 03 5F D6"));
                    doBypass(oxorany(0x4afd38), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0x4afd40), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0x4afd60), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0x4afd70), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0x4afd98), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0x4afdd0), oxorany("00 00 80 D2 C0 03 5F D6"));
					doBypass(oxorany(0x4b01f0), oxorany("00 00 80 D2 C0 03 5F D6"));
                    puts(oxorany("  LOGO BYPASS [✓] | Telegram: @Only_Pras  "));
		            puts(oxorany("  NusantaraHAX | Channel: @NusantaraHax  "));
		            puts(oxorany("  Codename : Glory  "));
    return 0;
}