#pragma once
#include <iostream>

namespace adapter {
    // OBD-II接口
    class OBDII_Interface {
    public:
        virtual std::string get_obd_data() const = 0;
        virtual ~OBDII_Interface() {}
    };

    // Ford OBD-II适配器
    class FordAdapter : public OBDII_Interface {
    private:
        std::string obd_data;

    public:
        FordAdapter(const std::string& data) : obd_data(data) {}

        std::string get_obd_data() const override {
            // 实现将标准OBD-II数据转化为Ford SCP协议的逻辑
            // ...
            return obd_data + " (Ford SCP)";
        }
    };

    // GM OBD-II适配器
    class GMAdapter : public OBDII_Interface {
    private:
        std::string obd_data;

    public:
        GMAdapter(const std::string& data) : obd_data(data) {}

        std::string get_obd_data() const override {
            // 实现将标准OBD-II数据转化为GM LAN协议的逻辑
            // ...
            return obd_data + " (GM LAN)";
        }
    };

    // Toyota OBD-II适配器
    class ToyotaAdapter : public OBDII_Interface {
    private:
        std::string obd_data;

    public:
        ToyotaAdapter(const std::string& data) : obd_data(data) {}

        std::string get_obd_data() const override {
            // 实现将标准OBD-II数据转化为Toyota ISO 9141协议的逻辑
            // ...
            return obd_data + " (Toyota ISO 9141)";
        }
    };

    // Volkswagen OBD-II适配器
    class VolkswagenAdapter : public OBDII_Interface {
    private:
        std::string obd_data;

    public:
        VolkswagenAdapter(const std::string& data) : obd_data(data) {}

        std::string get_obd_data() const override {
            // 实现将标准OBD-II数据转化为VW TP 2.0协议的逻辑
            // ...
            return obd_data + " (VW TP 2.0)";
        }
    };

    // OBD-II适配器工厂
    class OBDIIAdapterFactory {
    public:
        OBDII_Interface* create_adapter(const std::string& make, const std::string& obd_data) {
            if (make == "Ford") {
                return new FordAdapter(obd_data);
            }
            else if (make == "GM") {
                return new GMAdapter(obd_data);
            }
            else if (make == "Toyota") {
                return new ToyotaAdapter(obd_data);
            }
            else if (make == "Volkswagen") {
                return new VolkswagenAdapter(obd_data);
            }
            else {
                throw std::invalid_argument("Unsupported car make");
            }
        }
    };

    void test_adapter() {
        std::string obd_data = "Standard OBD-II data";
        OBDIIAdapterFactory adapter_factory;


        std::string make1 = "Ford";
        OBDII_Interface* adapter1 = adapter_factory.create_adapter(make1, obd_data);
        std::cout << adapter1->get_obd_data() << std::endl;
        delete adapter1;

        std::string make2 = "GM";
        OBDII_Interface* adapter2 = adapter_factory.create_adapter(make2, obd_data);
        std::cout << adapter2->get_obd_data() << std::endl;
        delete adapter2;

        std::string make3 = "Toyota";
        OBDII_Interface* adapter3 = adapter_factory.create_adapter(make3, obd_data);
        std::cout << adapter3->get_obd_data() << std::endl;
        delete adapter3;

        std::string make4 = "Volkswagen";
        OBDII_Interface* adapter4 = adapter_factory.create_adapter(make4, obd_data);
        std::cout << adapter4->get_obd_data() << std::endl;
        delete adapter4;
    };
}