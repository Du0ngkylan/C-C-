import math
import string
import sys

##################################
# Operation 1: read a text file ##
##################################
def read_file(filename):
  ''' 
    Read the text file with the given filename;
    return a list of the lines of text in the file.
  '''
    try:
        f = open(filename, 'r')
        return f.read()
    except IOError:
        print "Error opening or reading input file: ",filename
        sys.exit()
#################################################
# Operation 2: split the text lines into words ##
#################################################
# global variables needed for fast parsing
# translation table maps upper case to lower case and punctuation to spaces
translation_table = string.maketrans(string.punctuation+string.uppercase,
 " "*len(string.punctuation)+string.lowercase)
def get_words_from_line_list(text):
  '''
    Parse the given text into words.
    Return list of all words found.
  '''
    text = text.translate(translation_table)
    word_list = text.split()
    return word_list
##############################################
# Operation 3: count frequency of each word ##
##############################################
def count_frequency(word_list):
  '''
    Return a dictionary mapping words to frequency.
  '''
    D = {}
    for new_word in word_list:
        if new_word in D:
            D[new_word] = D[new_word]+1
        else:
            D[new_word] =  1
    return D
#############################################
## compute word frequencies for input file ##
#############################################
def word_frequencies_for_file(filename):
 '''
    Return dictionary of (word,frequency) pairs for the given file.
 '''
    line_list = read_file(filename)
    word_list = get_words_from_line_list(line_list)
    freq_mapping = count_frequency(word_list)
    print "File",filename,":"",
    print len(line_list),"lines,",
    print len(word_list),"words,"",
    print len(freq_mapping),"distinct words"
    return freq_mapping
def inner_product(D1,D2):
 '''
    Inner product between two vectors, where vectors
    are represented as dictionaries of (word,freq) pairs.
    Example: inner_product({"and":3,"of":2,"the":5},
    {"and":4,"in":1,"of":1,"this":2}) = 14.0 
 '''
    sum = 0.0
    for key in D1:
        if key in D2:
           sum += D1[key] * D2[key]
    return sum
def vector_angle(D1,D2):
 '''
    The input is a list of (word,freq) pairs, sorted alphabetically.
    Return the angle between these two vectors.
 '''
    numerator = inner_product(D1,D2)
    denominator=math.sqrt(inner_product(D1,D1)*inner_product(D2,D2))
    return math.acos(numerator/denominator)
def main():
   if len(sys.argv) != 3:
      print "Usage: docdist8.py filename_1 filename_2"
 else:
     filename_1 = sys.argv[1]
     filename_2 = sys.argv[2]
     sorted_word_list_1 = word_frequencies_for_file(filename_1)
     sorted_word_list_2 = word_frequencies_for_file(filename_2)
     distance = vector_angle(sorted_word_list_1,sorted_word_list_2)
     print("The distance between the documents is: %0.6f   (radians)"%distance)
if __name__ == "__main__":
 import profile
 profile.run("main()")