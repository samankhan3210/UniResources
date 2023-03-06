#ANUSHA SAAD 19K-0281
#HERMAIN QADIR 19K-1517
#SAMAN KHAN 19K-0354

words = []
speech = []
typ = []
name = []
data = []


def enter(p_name, word, types):
    typ.append(types)
    name.append(p_name)
    data.append(word)


def print_queue():
    i = 0
    output = ""
    while i < len(data):
        if output == "" and typ[i] == "Determiner":
            while name[i+1] == "Nom":
                print("S->", output,"", name[i], "VP", "\n", "S->", output, "", typ[i], "VP", "\n")
                output = output + " " + data[i]
                i += 1
        if output == "":
            print("S->", output, "", name[i], "VP" , "\n")
            print("S->", output, "", typ[i], "VP", "\n")
        else:
            print("S->", output, "", name[i], "\n", "S->", output, "", typ[i], "", name[i+1], "\n")

        output = output + " " + data[i]
        i += 1
        if i == len(data)-1:
            print("S->",output, " ", name[i], "\n", "S->", output, " ", typ[i], "\n")
            output = output + " " + data[i]
            print("S->",output)


def assign_type(word):
    j = 0
    file_names = ["Nouns.txt", "Pronouns.txt", "Verbs.txt", "Propernouns.txt", "Prepositions.txt", "Adjectives.txt",
                  "Determiners.txt", "Conjunctions.txt"]
    for i in file_names:
        f = open('D:/backup c/SEMESTER 4/TOA/Project/file/' + i, "r")
        content = f.read()
        content_list = content.split()
        if word in content_list:
            words.append(word)
            speech.append(i[0:-4])


def check(i, total):
    if i < 0:
        print("Invalid sentence structure!!!")
        exit(1)
    if i >= total:
        print("Valid Structure")
        print_queue()
        exit(1)
    else:
        return True


def check_pp(i, total, words, speech):
    if i < total:
        PP = ""
        if speech[i] == "Prepositions" and i != total - 1:
            PP += words[i]
            PP += " "
            enter("PP", words[i], speech[i])
            i += 1
            return check_np(i, total, words, speech)
        else:
            return -1
    else:
        return -1


def check_vp(i, total, words, speech):
    if i < total:
        VP = ""
        if speech[i] == "Verbs" and i == total - 1:
            VP += words[i]
            VP += " "
            enter("VP", words[i], speech[i])
            i += 1
            return i
        if speech[i] == "Verbs" and speech[i + 1] == 'Prepositions':
            VP += words[i]
            VP += " "
            enter("VP", words[i], speech[i])
            i += 1
            return check_pp(i, total, words, speech)
        if speech[i] == 'Verbs':
            VP += words[i]
            VP += " "
            enter("VP", words[i], speech[i])
            i += 1
            return check_np(i, total, words, speech)
    if i >= total:
        return i


def check_nom(i, total, words, speech):
    if i < total:
        nominal = ""
        if speech[i] == "Nouns":
            nominal += words[i]
            nominal += " "
            enter("NOM", words[i], speech[i])
            i += 1
            return check_nom(i, total, words, speech)
        if speech[i - 1] == "Determiners" and speech[i] != "Nouns":
            return -1
        else:
            return i
    if i >= total:
        return i


def check_ad(i, total, words, speech):
    if i < total:
        AD = ""
        if speech[i] == "Adjectives":
            AD += words[i]
            AD += " "
            enter("ADJ", words[i], speech[i])
            i += 1
            return check_nom(i, total, words, speech)
        else:
            i = i - 1
            return i
    if i >= total:
        return i


def check_np(i, total, words, speech):
    if i < total:
        NP = ""
        if speech[i] == "Pronouns" and total-1 != i or speech[i] == 'Propernouns':
            NP += words[i]
            NP += " "
            enter("NP", words[i], speech[i])
            i += 1
            return i
        if speech[i] == "Determiner" and speech[i+1] == 'Nouns' and i == 0:
            NP += words[i]
            NP += " "
            enter("NP", words[i], speech[i])
            i += 1
            i = check_nom(i, total, words, speech)
            return i
        if speech[i] == "Determiners" and speech[i+1] == 'Adjectives':
            NP += words[i]
            NP += " "
            enter("NP", words[i], speech[i])
            #enter("NP", words[i], speech[i])
            i += 1
            i = check_ad(i, total, words, speech)
            return i
        if speech[i] == "Determiners":
            NP += words[i]
            NP += " "
            enter("NP", words[i], speech[i])
            i += 1
            i = check_nom(i, total, words, speech)
            return i
        if speech[i - 1] == "Prepositions" and i > 0 and i != total-1:
            NP += words[i]
            NP += " "
            enter("NP", words[i], speech[i])
            i += 1
            i = check_nom(i, total, words, speech)
            return i
        if speech[i] == "Adjectives":
            NP += words[i]
            NP += " "
            enter("NP", words[i], speech[i])
            i += 1
            i = check_nom(i, total, words, speech)
            return i
        if speech[i] == "Nouns" and i > 0:
            NP += words[i]
            NP += " "
            enter("NP", words[i], speech[i])
            i += 1
            return i
        else:
            return -1

    if i >= total:
        return i


def main():
    var = "student cricket play"
    print("Sentence entered :", var)
    word_list = var.split()
    number_of_words = len(word_list)
    for i in word_list:
        assign_type(i)
    count = 0
    count = check_np(count, number_of_words, words, speech)
    if check(count, number_of_words):
        count = check_vp(count, number_of_words, words, speech)
    if check(count, number_of_words):
        count = check_pp(count, number_of_words, words, speech)
    if check(count, number_of_words):
        count = check_nom(count, number_of_words, words, speech)


main()
