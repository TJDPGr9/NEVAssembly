#pragma once
#include <iostream>
#include <string>

namespace potye {
    class SponsorshipContent {
    public:
        SponsorshipContent(const std::string& title, const std::string& details, const std::string& sponsor)
            : title(title), details(details), sponsor(sponsor) {}

        // 拷贝构造函数，用于实现对象的复制
        SponsorshipContent(const SponsorshipContent& other)
            : title(other.title), details(other.details), sponsor(other.sponsor) {}

        // 克隆函数，返回当前对象的副本
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
        // 创建原型对象
        SponsorshipContent originalContent("活动标题", "活动详情", "赞助商名称");

        // 复制对象生成新的活动内容
        SponsorshipContent* contentCopy1 = originalContent.clone();
        SponsorshipContent* contentCopy2 = originalContent.clone();

        contentCopy1->display(); // 显示原始对象信息
        std::cout << std::endl;
        contentCopy1->display(); // 显示复制后的对象1信息
        std::cout << std::endl;
        contentCopy2->display(); // 显示复制后的对象2信息

        delete contentCopy1;
        delete contentCopy2;
    }
}
#pragma once