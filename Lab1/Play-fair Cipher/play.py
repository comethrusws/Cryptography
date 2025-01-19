def create_matrix(key):
    key = key.upper().replace("J", "I")
    matrix = []
    used = set()

    # add key characters to the matrix
    for char in key:
        if char not in used and char.isalpha():
            used.add(char)
            matrix.append(char)

    # fill with remaining letters
    for char in "ABCDEFGHIKLMNOPQRSTUVWXYZ":
        if char not in used:
            matrix.append(char)

    return [matrix[i:i + 5] for i in range(0, 25, 5)]


def position(matrix, letter):
    if letter == "J":
        letter = "I"  # treat I and J as the same
    for row in range(5):
        for col in range(5):
            if matrix[row][col] == letter:
                return row, col


def digraphencrypp(matrix, digraph):
    row1, col1 = position(matrix, digraph[0])
    row2, col2 = position(matrix, digraph[1])

    if row1 == row2:  # same row
        return matrix[row1][(col1 + 1) % 5] + matrix[row2][(col2 + 1) % 5]
    elif col1 == col2:  # same column
        return matrix[(row1 + 1) % 5][col1] + matrix[(row2 + 1) % 5][col2]
    else:  # rectangle
        return matrix[row1][col2] + matrix[row2][col1]


def playfair_encrypt(plaintext, key):
    matrix = create_matrix(key)
    plaintext = plaintext.upper().replace("J", "I")
    cleaned_text = ""

    # remove non-alpha and add filler for dupes
    for char in plaintext:
        if char.isalpha():
            if cleaned_text and cleaned_text[-1] == char:
                cleaned_text += "X"
            cleaned_text += char

    if len(cleaned_text) % 2 != 0:
        cleaned_text += "X"  # pad with X if needed

    encrypted_text = ""
    for i in range(0, len(cleaned_text), 2):
        digraph = cleaned_text[i:i + 2]
        encrypted_text += digraphencrypp(matrix, digraph)

    return encrypted_text


plaintext = input("enter plaintext: ")
key = input("enter key: ")

result = playfair_encrypt(plaintext, key)
print(f"encrypted text: {result}")
