#include <iostream>
#include <vector>
#include <string>
#include "sean_parent_polymorphism.hpp"

using document_t = std::vector<object_t>;

void draw(const document_t &x, std::ostream &out, std::size_t position)
{
    out << std::string(position, ' ') << "<document>\n";
    for (const auto &e : x)
    {
        e.draw(out, position +2);
    }
    out << std::string(position, ' ') << "</document>\n";
}

class my_class_t
{
public:
    void draw(std::ostream &out, std::size_t position) const
    {
        out << std::string(position, ' ') << "my_class_t\n";
    }
    std::string get_typename() const
    {
        return std::string("my_class_t");
    }
};

class string_writer
{
public:
    void draw(std::ostream &out, std::size_t position) const
    {
        out << std::string(position, ' ') << my_string << std::endl;
    }
    std::string get_typename() const
    {
        return std::string("string_writer");
    }
private:
    std::string my_string{"blah"};
};

class int_writer
{
public:
    int_writer(int n) : my_number(n) {}
    void draw(std::ostream &out, std::size_t position) const
    {
        out << std::string(position, ' ') << my_number << std::endl;
    }
    std::string get_typename() const
    {
        return std::string("int_writer");
    }
private:
    int my_number;
};

void sean_parent_polymorphism()
{
    document_t doc;
    doc.emplace_back(my_class_t());
    doc.emplace_back(string_writer());
    doc.emplace_back(int_writer(8));
    draw(doc, std::cout, 0);

    auto element = doc[0];
    element.draw(std::cout, 0);
    std::cout << "\n" << element.get_typename() << "\n";

}
