def __shuffle__(chars):
    # This private function is a user defined function to shuffle the chars. To Shuffle the chars its does no of random
    # swap operations.
    import random
    if chars is []:
        return []
    else:
        char_len = len(chars)
        for i in range(char_len):
            random_int1 = random.randint(0, char_len - 1)
            random_int2 = random.randint(0, char_len - 1)
            temp = chars[random_int1]
            chars[random_int1] = chars[random_int2]
            chars[random_int2] = temp
        return chars


def scramble(s):
    # This function is used to scramble properly the input word taking care of punctuation marks
    __punctuations__ = {',', '.', '?', '!', ';'}  # Set of punctuations to be recognised
    if s is None:  # None Check
        return ""
    else:
        str_len = len(s)
        if str_len <= 3:  # Not Scrambling for short length data
            return s
        else:
            # Extracting 1st and last Character of the word
            fst_char = s[0]
            lst_char = s[-1]
            if lst_char in __punctuations__:  # punctuation check for last character
                # Scrambling Characters using user defined shuffle function defined above
                center_chars = list(s[1:-2])
                while center_chars == list(s[1:-2]):
                    __shuffle__(center_chars)
                op_str = fst_char + "".join(center_chars) + s[-2] + lst_char
            else:
                # Scrambling Characters using user defined shuffle function defined above
                center_chars = list(s[1:-1])
                while center_chars == list(s[1:-1]):
                    __shuffle__(center_chars)
                op_str = fst_char + "".join(center_chars) + lst_char
            return op_str
