#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include<filesystem>
using namespace std::filesystem;
using namespace std;

static int weight_coefficient[17] = { 8, 7, 6, 5, 4, 3, 2, 10, 0, 9, 8, 7, 6, 5, 4, 3, 2 };

class VINDecoder {
public:
    VINDecoder(const nlohmann::json& data) : jsonData(data) {}

    bool decodeVIN(const std::string& vin) {
        if (vin.length() != 17) {
            cerr << "错误：无效的VIN码长度" << endl;
            return false;
        }

        if (!decodeWMI(vin.substr(0, 3)) ||
            !decodeVDS(vin.substr(3, 5)) ||
            !decodeVIS(vin.substr(9, 8))) {
            return false;
        }

        // 验证第九位数字（校验位）
        if (!validateCheckDigit(vin)) {
            cerr << "错误：VIN码验证失败" << endl;
            exit(1);
            return false;
        }

        return true;
    }

    // 获取解码后的信息的公有成员函数
    const std::string& getRegion() const { return region; }
    const std::string& getManufacturer() const { return manufacturer; }
    const std::string& getVehicleType() const { return vehicleType; }
    const std::string& getBodyStyle() const { return bodyStyle; }
    const std::string& getTransmission() const { return transmission; }
    const std::string& getYear() const { return year; }
    const std::string& getX() const { return x; }
    const std::string& getY() const { return y; }
    const std::string& getZ() const { return z; }

private:
    bool decodeWMI(const std::string& wmiPart) {
        region = jsonData["WMI_1"].value(wmiPart.substr(0, 1), "未知");
        manufacturer = jsonData["WMI_2"].value(wmiPart.substr(1, 1), "未知");
        vehicleType = jsonData["WMI_3"].value(wmiPart.substr(2, 1), "未知");
        return true;
    }

    bool decodeVDS(const std::string& vdsPart) {
        bodyStyle = jsonData["VDS_4"].value(vdsPart.substr(0, 1), "未知");
        transmission = jsonData["VDS_5"].value(vdsPart.substr(1, 1), "未知");
        x = jsonData["VDS_6"].value(vdsPart.substr(2, 1), "未知");
        y = jsonData["VDS_78"].value(vdsPart.substr(3, 2), "未知");
        // 根据需要添加更多的 VDS 解码逻辑...
        return true;
    }

    bool decodeVIS(const std::string& visPart) {
        year = jsonData["VIS_10"].value(visPart.substr(0, 1), "未知");
        z = jsonData["BMW"].value(visPart.substr(1, 1), "未知");
        // 根据需要添加更多的 VIS 解码逻辑...
        return true;
    }

    bool validateCheckDigit(const std::string& vin) {
        int checkDigit = vin[8];

        int sum = 0;
        for (int i = 0; i < 17; ++i) {
            if (vin[i] >= '0' && vin[i] <= '9') {
                sum += (vin[i] - '0') * weight_coefficient[i];
            }
            else if (vin[i] >= 'A' && vin[i] <= 'Z' && vin[i] != 'I' && vin[i] != 'O' && vin[i] != 'Q') {
                if (vin[i] >= 'A' && vin[i] <= 'I')
                    sum += (vin[i] - 'A' + 1) * weight_coefficient[i];
                else if (vin[i] >= 'J' && vin[i] <= 'R')
                    sum += (vin[i] - 'J' + 1) * weight_coefficient[i];
                else if (vin[i] >= 'S' && vin[i] <= 'Z')
                    sum += (vin[i] - 'S' + 2) * weight_coefficient[i];
            }
            else {
                cout << "VIN中不能包含 I、O、Q 三个英文字母，请重新检查VIN码" << endl;
                // 直接终止程序
                exit(1);
                return false;
            }
        }

        int remainder = sum % 11;
        if (remainder == 10) {
            //cout << remainder << endl;
            return checkDigit == 'X';
        }
        else {
            //cout << remainder << endl;
            return checkDigit == (remainder + '0');
        }
    }

private:
    const nlohmann::json& jsonData;

    std::string region;
    std::string manufacturer;
    std::string vehicleType;
    std::string bodyStyle;
    std::string transmission;
    std::string year;
    std::string x;
    std::string y;
    std::string z;
};
namespace Interpreter {
    int test() {
        try {
            // 从文件读取 JSON 数据
            path currentPath = current_path();

            while (currentPath.filename().string() != "out")
                currentPath = currentPath.parent_path();
            currentPath = currentPath.parent_path();
            current_path(currentPath);
            path subdirectory("Interpreter Pattern");

            nlohmann::json jsonData;
            try {
                if (exists(currentPath / subdirectory)) {
                    current_path(currentPath / subdirectory);
                    cout << "Successfully enter the subdirectory:" << currentPath / subdirectory << endl;
                }
            }
            catch (filesystem_error& e) {
                std::cerr << "Exception Encountered: " << e.what() << endl;
            }
            ifstream jsonFile("data.json");
            // 检查文件是否成功打开
            if (!jsonFile.is_open()) {
                cerr << "错误：无法打开JSON文件" << endl;
                return 1;
            }

            // 从文件读取 JSON 数据
            jsonFile >> jsonData;
            jsonFile.close();

            // VIN 码待解码
            std::string vin = "21VAM033936123456";

            // 创建 VIN 解码器
            VINDecoder vinDecoder(jsonData);

            // 解码 VIN 码
            bool ret = vinDecoder.decodeVIN(vin);

            // 输出解码信息
            cout << "Region:" << vinDecoder.getRegion() << endl;
            cout << "Manufacture:" << vinDecoder.getManufacturer() << endl;
            cout << "Type of Vehicle:" << vinDecoder.getVehicleType() << endl;
            cout << "Style of body:" << vinDecoder.getBodyStyle() << endl;
            cout << "Transmission&Fuel system:" << vinDecoder.getTransmission() << endl;
            cout << "Configuration for safety:" << vinDecoder.getX() << endl;
            cout << "Type of body:" << vinDecoder.getY() << endl;
            cout << "Built Year:" << vinDecoder.getYear() << endl;
            cout << "Assembly Plant:" << vinDecoder.getZ() << endl;
            cout << "Manufacture seq. No.:" << vin.substr(11, 6) << endl;

            if (ret) {
                cout << "VIN code has been verified successfully" << endl;
            }
            else {
                cout << "VIN code verification failed" << endl;
            }
        }
        catch (const nlohmann::json::parse_error& e) {
            // 输出详细的解析错误信息
            cerr << "JSON parse error：" << e.what() << " At byte" << e.byte << endl;
            return 1;
        }
        catch (const exception& e) {
            // 捕获其他可能的异常
            cerr << "Exception occured：" << e.what() << endl;
            return 1;
        }

        return 0;
    }
}
