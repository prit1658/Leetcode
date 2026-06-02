#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows == 1 || numRows >= len)
        return s;

    char *result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;
    int cycleLen = 2 * numRows - 2;

    for (int row = 0; row < numRows; row++) {
        for (int j = row; j < len; j += cycleLen) {

            result[index++] = s[j];

            int secondPos = j + cycleLen - 2 * row;

            if (row != 0 && row != numRows - 1 &&
                secondPos < len) {
                result[index++] = s[secondPos];
            }
        }
    }

    result[index] = '\0';
    return result;
}