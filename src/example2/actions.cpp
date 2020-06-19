#include <boost/spirit/home/x3.hpp>

#include <iostream>
#include <vector> 
// Presented are various ways to attach semantic actions
// * Using plain function pointer
// * Using simple function object

namespace client
{
    namespace x3 = boost::spirit::x3;
    using x3::_attr;

    struct print_action
    {
        template <typename Context>
        void operator()(Context const& ctx) const
        {
            std::cout << _attr(ctx) << std::endl;
        }
    };
}


int main()
{
    using boost::spirit::x3::int_;
    using boost::spirit::x3::parse;
    using client::print_action;

    // example using function object
    {
        const std::string example = "{43}";
        parse(example.begin(), example.end(), '{' >> int_[print_action()] >> '}');
    }

    // example using lambda
    {   
        using boost::spirit::x3::_attr;
        const std::string example = "{43}";
        std::vector<int> v;
        auto f = [&v](auto& ctx) { v.push_back(_attr(ctx)); };
        parse(example.begin(), example.end(), '{' >> int_[f] >> '}');
        std::cout << v[0] << std::endl;
    }

    return 0;
}
