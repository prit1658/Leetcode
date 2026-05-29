int lengthOfLongestSubstring(char* s) {
    int lastSeen[128];

    for (int i = 0; i < 128; i++) {
        lastSeen[i] = -1;
    }

    int maxLength = 0;
    int start = 0;

    for (int end = 0; s[end] != '\0'; end++) {

        if (lastSeen[s[end]] >= start) {
            start = lastSeen[s[end]] + 1;
        }

        lastSeen[s[end]] = end;

        int currentLength = end - start + 1;

        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}