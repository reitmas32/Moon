import subprocess
import glob
import os
import errno

dir_markdown = '../docs/markdown/'

def main():
    # root_dir needs a trailing slash (i.e. /root/dir/)
    for filename in glob.iglob(dir_markdown + '**/*.md', recursive=True):
        file_md = open(filename, "r")
        data = file_md.read()
        file_md.close()
        name_var = filename.replace(".md", "").replace(dir_markdown, "").replace("/", "_").replace("-", "_").replace("..","")
        name_var += "_md"
        file = filename.replace(".md", "").replace("markdown", "moon_docs/lib/markdown")
        data_dart = "final String " + name_var + " = '''\n" + data + "\n''';"
        data_dart = data_dart.replace("$", "\$")
        if not os.path.exists(os.path.dirname(file)):
            try:
                os.makedirs(os.path.dirname(file))
            except OSError as exc: # Guard against race condition
                if exc.errno != errno.EEXIST:
                    raise
        file_dart = open(file + ".dart", "w")
        file_dart.write(data_dart)
        file_dart.close()


if __name__ == "__main__":
    main()
