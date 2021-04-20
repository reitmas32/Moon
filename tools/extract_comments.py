import sys
import re
import os.path
import codecs
import os

encoding = 'cp932'

def comment_finder(text):
    pattern = re.compile( r'//.*?$|/\*.*?\*/', re.DOTALL | re.MULTILINE)
    result = pattern.findall(text)
    return result

def print_command(filename):

    codefile = codecs.open(filename,'r', encoding)
    commentfile = codecs.open(filename+".cmt",'w', encoding)
    lines=codefile.read()
    codefile.close()
    #the list of comments
    list_of_comments = comment_finder(lines)
    for comment in list_of_comments:
        #print comment[0:2]
        if comment[0:2] == "//":
                comment_to_write = comment[2:]
        else:
            comment_to_write = comment[2:-2]
        if comment_to_write.endswith("\r"):
            comment_to_write = comment_to_write[0:-1]
        if len(comment_to_write)!=0:
            commentfile.write(comment_to_write)
            commentfile.write(os.linesep)
    commentfile.close()
    commentFile = codecs.open(filename+".cmt",'r', encoding)
    comments = commentFile.read()
    commentFile.close()
    newComments = comments.replace(" * ", "").replace("*", "").replace("\n\n","\n").replace("\n ", "").replace("@", ",\n@").replace("\n,",",").replace("  ","").replace(" ,",",")
    commentFile = codecs.open(filename+".cmt",'w', encoding)
    commentFile.write(newComments)
    commentFile.close()

def visitor(filters, dirname, names):
    mynames = filter(lambda n : os.path.splitext(n)[1].lower() in filters, names)
    for name in mynames:
        fname = os.path.join(dirname, name)
        if not os.path.isdir(fname):
            print_command(fname)
'''
Usage:
    python extract_comments.py file_1 file_2 ...
'''
if __name__ == "__main__":
    for file in sys.argv[1:]:
        print_command(file)