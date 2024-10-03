#include <Arduino.h>
#include <stdarg.h>
extern "C"
{
#include "log.h"
}

extern "C" void guage_log(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    char buffer[256]; // Adjust the buffer size as needed
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    Serial.printf("%s", buffer);
}