#pragma once
#include <iostream>
#include <string>

namespace potye {
    class SponsorshipContent {
    public:
        SponsorshipContent(const std::string& title, const std::string& details, const std::string& sponsor)
            : title(title), details(details), sponsor(sponsor) {}

        // �������캯��������ʵ�ֶ���ĸ���
        SponsorshipContent(const SponsorshipContent& other)
            : title(other.title), details(other.details), sponsor(other.sponsor) {}

        // ��¡���������ص�ǰ����ĸ���
        SponsorshipContent* clone() {
            return new SponsorshipContent(*this);
        }

        void display() {
            std::cout << title << std::endl << details << std::endl << sponsor << std::endl;
        }

    private:
        std::string title;
        std::string details;
        std::string sponsor;
    };
    void test_pototype() {
        // ����ԭ�Ͷ���
        SponsorshipContent originalContent("�����", "�����", "����������");

        // ���ƶ��������µĻ����
        SponsorshipContent* contentCopy1 = originalContent.clone();
        SponsorshipContent* contentCopy2 = originalContent.clone();

        contentCopy1->display(); // ��ʾԭʼ������Ϣ
        std::cout << std::endl;
        contentCopy1->display(); // ��ʾ���ƺ�Ķ���1��Ϣ
        std::cout << std::endl;
        contentCopy2->display(); // ��ʾ���ƺ�Ķ���2��Ϣ

        delete contentCopy1;
        delete contentCopy2;
    }
}
#pragma once