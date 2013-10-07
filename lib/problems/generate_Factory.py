#!/usr/bin/env python

import os
import re
import sys

def get_list_of_problems(source_dir):
    """ Returns a list of tuples. In the first entry is an integer,
    the second the path to the corresponding header file"""

    problems = []

    dir_re = re.compile("\d{4}-\d{4}")
    header_re = re.compile("Problem(\d)+\.h$")

    for dirpath, dirs, files in os.walk(source_dir):
        if re.match(dir_re, os.path.split(dirpath)[-1]):
            for f in files:
                match = re.match(header_re, f)
                if match:
                    problems.append((match.group(1), dirpath + os.sep + f))

    return problems

def print_header(out):
    out.write("#include \"problems/Factory.h\"\n" +
              "#include \"problems/Invalid.h\"\n" +
              "#include \"problems/Problem.h\"\n" +
              "using problems::Problem;\n" +
              "#include \"util/Pointers.h\"\n\n")

def print_includes(out, problems):
    for p in problems:
        out.write("#include \"" + p[1] + "\"\n")
    out.write("\n")

def print_create(out, problems):
    indent = "  "
    indent2 = indent + indent
    indent3 = indent2 + indent

    out.write("std::unique_ptr<Problem> problems::Factory::create(unsigned int num) {\n" +
              indent + "switch(num) {\n")

    for p in problems:
        out.write(indent2 + "case " + str(p[0]) + ": {\n" +
                  indent3 + "return make_unique<Problem" + str(p[0]) + ">();\n" +
                  indent2 + "}\n")

    out.write(indent2 + "default: {\n" +
              indent3 + "return make_unique<Invalid>();\n" +
              indent2 + "}\n" +
              indent + "}\n" )

    out.write("}\n")


def make_Factory(args):
    if len(args) != 3:
        print "Invalid usage. First arg is out directory, second arg is source directory"
        print "args: " + str(args)
        sys.exit(1)

    out_dir = args[1] + "/"
    problems = get_list_of_problems(args[2])

    out = open(out_dir + "Factory.cpp", 'w')
    print_header(out)
    print_includes(out, problems)
    print_create(out, problems)
    out.write("\n")
    out.close()

if __name__ == "__main__":
    make_Factory(sys.argv)

