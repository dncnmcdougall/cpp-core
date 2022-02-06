#pragma once

#include <iostream>

namespace logging
{
enum class Level {
    Error=0,
    Warning=1,
    Message=2,
    Debug=3
};


class Logger
    {
        public:

        Logger(Level level) : m_level(level) {};

        typedef std::basic_ostream<char, std::char_traits<char>> CoutType;
        Logger& operator<<(CoutType& (*value)(CoutType&) ) { 
            if ( m_level <= s_level) {
                switch(m_level) {
                    case Level::Error: [[fallthrough]];
                    case Level::Debug:
                        std::cerr<<value;
                        break;
                    case Level::Message: [[fallthrough]];
                    case Level::Warning:
                        std::cout<<value;
                        break;
                    default:
                        std::cout<<value;
                        break;
                }
            }
            return *this;
        };

        template<typename T>
        Logger& operator<<(const T& value) { 
            if ( m_level <= s_level) {
                switch(m_level) {
                    case Level::Error: [[fallthrough]];
                    case Level::Debug:
                        std::cerr<<value;
                        break;
                    case Level::Message: [[fallthrough]];
                    case Level::Warning:
                        std::cout<<value;
                        break;
                    default:
                        std::cout<<value;
                        break;
                }
            }
            return *this;
        }

        friend void setLevel(Level level);

        private:
        const Level m_level;

        static Level s_level;

    };

void setLevel(Level level) 
{ 
    Logger::s_level=level; 
};

Logger error(Level::Error);
Logger warn(Level::Warning);
Logger message(Level::Message);
Logger debug(Level::Debug);

Level Logger::s_level = Level::Message;

};
