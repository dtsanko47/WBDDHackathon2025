#include <curl/curl.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// Website stores statistics for hockey teams from 1990-2011
// URL: https://www.scrapethissite.com/pages/forms/?page_num=1

// Receives downloaded data from a URL
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    // Appends all data into a single string
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    // Returns the size of the downloaded data
    return size * nmemb;
}

// Collects data of hockey teams from 1990-2011 and stores in a text file "hockey_data.txt"
void getData() {
    //Start at page 1
    int pageNum = 1;
    string url = "https://www.scrapethissite.com/pages/forms/?page_num=";
    CURL* curl = curl_easy_init();
    string fullURL = "";

    if (!curl) {
        cerr << "Failed to initialize curl" << endl;
    }

    //Write to file "hockey_data.txt"
    ofstream file;
    file.open("hockey_data.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file" << endl;
    }

    // Iterate through all 24 pages
    while (pageNum < 25) {
        // Access each page by concatenating page number to the end of the URL
        fullURL = url + to_string(pageNum);
        string htmlData;

        // Converts string to C-string for libcurl
        curl_easy_setopt(curl, CURLOPT_URL, fullURL.c_str());
        // Each time libcurl receives data, call WriteCallBack
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        // Append data to htmlData string
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &htmlData);

        // Connect to server and send HTTP request
        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            cout << "Error: " << curl_easy_strerror(res) << endl;
        } else {
            // Tag for each team
            string toFind = "tr class=\"team\"";
            // Tag for each data value from each team
            string nameTag = "td class=\"name\"";
            string yearTag = "td class=\"year\"";
            string winsTag = "td class=\"wins\"";
            string lossesTag = "td class=\"losses\"";
            // Pct has both text-danger and text-success classes, check for each one
            string pctTagDanger = "td class=\"pct text-danger\"";
            string pctTagSuccess = "td class=\"pct text-success\"";
            string gfTag = "td class=\"gf\"";
            string gaTag = "td class=\"ga\"";
            // Pct has both text-danger and text-success classes, check for each one
            string diffTagDanger = "td class=\"diff text-danger\"";
            string diffTagSuccess = "td class=\"diff text-success\"";
            // Store tags in an array and iterate through each one to get its data
            string tags[10] = {nameTag, yearTag, winsTag, lossesTag, pctTagDanger, pctTagSuccess, gfTag, gaTag, diffTagDanger, diffTagSuccess};
            int arraySize = sizeof(tags) / sizeof(tags[0]);
            size_t pos = 0;
            string trContent = "";
            // Run loop until substring not found (when no tags left)
            while ((pos = htmlData.find(toFind, pos)) != string::npos) {
                size_t endPos = htmlData.find("</tr>", pos);
                // If endPos is empty then break
                if (endPos == string::npos) {
                    break;
                }
                trContent = htmlData.substr(pos, endPos - pos + 5);
                for (int i = 0; i < arraySize; i++) {
                    size_t tagPos = trContent.find(tags[i]);
                    if (tagPos != string::npos) {
                        // Move to the first '>' after the class, ignoring extra classes
                        tagPos = trContent.find('>', tagPos);
                        if (tagPos != string::npos) {
                            // Start of content
                            tagPos++;
                            size_t tagEnd = trContent.find("</td>", tagPos);
                            if (tagEnd != string::npos) {
                                string tagInfo = trContent.substr(tagPos, tagEnd - tagPos);

                                // Trim whitespace
                                tagInfo.erase(tagInfo.begin(), find_if(tagInfo.begin(), tagInfo.end(),
                                    [](unsigned char ch) { return !isspace(ch); }));
                                tagInfo.erase(find_if(tagInfo.rbegin(), tagInfo.rend(),
                                    [](unsigned char ch) { return !isspace(ch); }).base(), tagInfo.end());

                                if (i < 8) {
                                    cout << tagInfo << ", ";
                                    file << tagInfo << ", ";
                                } else {
                                    cout << tagInfo;
                                    file << tagInfo;
                                }
                            }
                        }
                    }
                }
                cout << endl;
                file << endl;

                pos = endPos + 5;
            }
        }
        pageNum++;
    }
    curl_easy_cleanup(curl);
    file.close();
}

int main() {
    getData();
    return 0;
}
