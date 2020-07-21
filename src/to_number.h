#pragma once

#define CHK_VALID  printf("    %s       %s\n", \
                         errno != ERANGE ? "Yes" : "No ", \
                         *ptr  == '\0' ? "Yes" : "No ")


void format_string_to_number(int argc, char* argv[]);
