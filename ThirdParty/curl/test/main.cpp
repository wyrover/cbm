#include <Windows.h>
#include "curl/curl.h"
#pragma comment(lib,"libcurl.lib")

int main(int argc, char* argv[])
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");

		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	getchar();
	return 0;
}