#include "logging.h"

namespace logging
{

Logging error(Logging::ERROR);
Logging warn(Logging::WARNING);
Logging message(Logging::MESSAGE);
Logging debug(Logging::DEBUG);

Logging::Level Logging::s_level = MESSAGE;
}
