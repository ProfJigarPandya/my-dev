# Scramble function will scramble the input word in proper manner
def scramble(str_word):
    import random
    __punctuations__ = {',', '.', '?', '!', ';'}  # Set of punctuations to be recognised
    if str_word is None:  # None Check
        return ""
    else:
        str_len = len(str_word)
        if str_len <= 3:  # Not Scrambling for short length data
            return str_word
        else:
            # Extracting 1st and last Character of the word
            fst_char = str_word[0]
            lst_char = str_word[-1]
            if lst_char in __punctuations__:  # punctuation check for last character
                # Scrambling Characters using random.shuffle() inbuilt Library
                center_chars = list(str_word[1:-2])
                while center_chars == list(str_word[1:-2]):
                    random.shuffle(center_chars)
                op_str = fst_char + "".join(center_chars) + str_word[-2] + lst_char
            else:
                # Scrambling Characters using random.shuffle() inbuilt Library
                center_chars = list(str_word[1:-1])
                while center_chars == list(str_word[1:-1]):
                    random.shuffle(center_chars)
                op_str = fst_char + "".join(center_chars) + lst_char
            return op_str
