#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <spdlog/spdlog.h>

static std::vector<std::string> readParagraphs(const std::string& filename) {
    std::vector<std::string> paragraphs;
    std::ifstream file(filename);
    std::string line;
    std::string paragraph;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (line.empty()) {
                if (!paragraph.empty()) {
                    paragraphs.push_back(paragraph);
                    paragraph.clear();
                }
            } else {
                if (!paragraph.empty()) {
                    paragraph += " ";
                }
                paragraph += line;
            }
        }
        if (!paragraph.empty()) {
            paragraphs.push_back(paragraph);
        }
        file.close();
    } else {
        spdlog::error("Could not open file");
    }

    return paragraphs;
}