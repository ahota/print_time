#include <chrono>
#include <iomanip>
#include <ostream>

void print_time(int ms, std::ostream &ostr=std::cout)
{
    int h =  ms             / 3600000;
    int m = (ms %= 3600000) /   60000;
    int s = (ms %=   60000) /    1000;
    ms %= 1000;

    ostr << std::setw(2) << std::setfill('0') << h << ":";
    ostr << std::setw(2) << std::setfill('0') << m << ":";
    ostr << std::setw(2) << std::setfill('0') << s << ".";
    ostr << std::setw(3) << std::setfill('0') << ms << std::endl;
}

template<typename REP, typename RATIO>
void print_time(std::chrono::duration<REP, RATIO> delta,
                std::ostream &ostr=std::cout)
{
    using namespace std::chrono;
    print_time(duration_cast<milliseconds>(delta).count(), ostr);
}
