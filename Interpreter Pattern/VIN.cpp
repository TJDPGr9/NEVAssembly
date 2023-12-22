#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;

static int weight_coefficient[17] = { 8, 7, 6, 5, 4, 3, 2, 10, 0, 9, 8, 7, 6, 5, 4, 3, 2 };

class VINDecoder {
public:
    VINDecoder(const nlohmann::json& data) : jsonData(data) {}

    bool decodeVIN(const std::string& vin) {
        if (vin.length() != 17) {
            cerr << "������Ч��VIN�볤��" << endl;
            return false;
        }

        if (!decodeWMI(vin.substr(0, 3)) ||
            !decodeVDS(vin.substr(3, 5)) ||
            !decodeVIS(vin.substr(9, 8))) {
            return false;
        }

        // ��֤�ھ�λ���֣�У��λ��
        if (!validateCheckDigit(vin)) {
            cerr << "����VIN����֤ʧ��" << endl;
            exit(1);
            return false;
        }

        return true;
    }

    // ��ȡ��������Ϣ�Ĺ��г�Ա����
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
        region = jsonData["WMI_1"].value(wmiPart.substr(0, 1), "δ֪");
        manufacturer = jsonData["WMI_2"].value(wmiPart.substr(1, 1), "δ֪");
        vehicleType = jsonData["WMI_3"].value(wmiPart.substr(2, 1), "δ֪");
        return true;
    }

    bool decodeVDS(const std::string& vdsPart) {
        bodyStyle = jsonData["VDS_4"].value(vdsPart.substr(0, 1), "δ֪");
        transmission = jsonData["VDS_5"].value(vdsPart.substr(1, 1), "δ֪");
        x = jsonData["VDS_6"].value(vdsPart.substr(2, 1), "δ֪");
        y = jsonData["VDS_78"].value(vdsPart.substr(3, 2), "δ֪");
        // ������Ҫ��Ӹ���� VDS �����߼�...
        return true;
    }

    bool decodeVIS(const std::string& visPart) {
        year = jsonData["VIS_10"].value(visPart.substr(0, 1), "δ֪");
        z = jsonData["BMW"].value(visPart.substr(1, 1), "δ֪");
        // ������Ҫ��Ӹ���� VIS �����߼�...
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
                cout << "VIN�в��ܰ��� I��O��Q ����Ӣ����ĸ�������¼��VIN��" << endl;
                // ֱ����ֹ����
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

int main() {
    try {
        // ���ļ���ȡ JSON ����
        nlohmann::json jsonData;
        ifstream jsonFile("data.json");

        // ����ļ��Ƿ�ɹ���
        if (!jsonFile.is_open()) {
            cerr << "�����޷���JSON�ļ�" << endl;
            return 1;
        }

        // ���ļ���ȡ JSON ����
        jsonFile >> jsonData;
        jsonFile.close();

        // VIN �������
        std::string vin = "21VAM033936123456";

        // ���� VIN ������
        VINDecoder vinDecoder(jsonData);

        // ���� VIN ��
        bool ret = vinDecoder.decodeVIN(vin);

        // ���������Ϣ
        cout << "������" << vinDecoder.getRegion() << endl;
        cout << "�����̣�" << vinDecoder.getManufacturer() << endl;
        cout << "�������ͣ�" << vinDecoder.getVehicleType() << endl;
        cout << "������" << vinDecoder.getBodyStyle() << endl;
        cout << "����ϵͳ��ȼ�����ͣ�" << vinDecoder.getTransmission() << endl;
        cout << "��ȫϵͳ���ã�" << vinDecoder.getX() << endl;
        cout << "�������ͣ�" << vinDecoder.getY() << endl;
        cout << "������ݣ�" << vinDecoder.getYear() << endl;
        cout << "��װ������" << vinDecoder.getZ() << endl;
        cout << "����˳��ţ�" << vin.substr(11, 6) << endl;

        if (ret) {
            cout << "VIN����֤�ɹ�" << endl;
        }
        else {
            cout << "VIN����֤ʧ��" << endl;
        }
    }
    catch (const nlohmann::json::parse_error& e) {
        // �����ϸ�Ľ���������Ϣ
        cerr << "JSON��������" << e.what() << " ���ֽ� " << e.byte << endl;
        return 1;
    }
    catch (const exception& e) {
        // �����������ܵ��쳣
        cerr << "�����쳣��" << e.what() << endl;
        return 1;
    }

    return 0;
}
