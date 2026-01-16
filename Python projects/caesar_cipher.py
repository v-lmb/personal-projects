#!/usr/bin/python3
# first version of Caesar cipher
# currently only handles uppercase letters
# coming soon: handling of lowercase letters
# perhaps numbers

def c_cypher(message, shift=3, decode=False):
    if decode:
        shift = -shift

    result = ""

    message = message.replace("é", "e").replace("à", "a").replace("ù", "u").replace("è", "e")

    for letter in message.upper():
        if letter.isalpha():
            ascii_value = ord(letter) - ord("A")
            shift_value = (ascii_value + shift) % 26
            result = result + chr(shift_value + ord("A"))
        else:
            result = result + letter
    return result


def main():
    message = input("Your message (capital letters): ")
    print(c_cypher(message))

    encoded = c_cypher(message)
    decoded = c_cypher(encoded, decode=True)

    print("Encoded message: ", encoded)
    print("Decoded message: ", decoded)


if __name__ == "__main__":
    main()
