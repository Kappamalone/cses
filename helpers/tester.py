#!/usr/bin/env python3

"""
Quick and dirty unit testing script for competitive programs

Expected directory structure:
tests/your_problem.txt
your_problem.cpp
"""

import argparse
import subprocess

test_file_delim = "---"
test_file_answer_delim = ">"
test_case_delimiter = "==========="


def main():
    parser = argparse.ArgumentParser(
        description="unit tester for competitive programming"
    )
    parser.add_argument("target", help="cpp program")
    args = parser.parse_args()

    # compile cpp program
    result = subprocess.run(["make", f"TARGET={args.target}"])
    if result.returncode != 0:
        return

    # parse test file
    test_cases = []
    input_buf = ""
    output_buf = ""
    is_input = True

    with open(f"./tests/{args.target}.txt", "r") as f1:
        for line in f1.readlines():
            line = line.strip()
            if line == test_file_delim:
                test_cases.append((input_buf, output_buf))
                input_buf = ""
                output_buf = ""
                is_input = True
            elif line == test_file_answer_delim:
                is_input = False
            else:
                if is_input:
                    input_buf += line + "\n"
                else:
                    output_buf += line + "\n"

    if input_buf != "":
        test_cases.append((input_buf, output_buf))

    for test_case in test_cases:
        result = subprocess.run(
            [f"./build/{args.target}"],
            input=test_case[0],
            capture_output=True,
            text=True,
        )

        print(f"{test_case_delimiter}")
        print(f"\033[1mInput:\033[0m\n{test_case[0]}")
        if result.stdout.strip() == test_case[1].strip():
            print("\033[92mPASSED\033[0m")
        else:
            print("\033[91mFAILED\033[0m")
            print(
                f"\033[1mOutput:\033[0m\n{result.stdout.strip()}\n\033[1mExpected:\033[0m\n{test_case[1].strip()}\n"
            )
            if result.stderr.strip() != "":
                print(f"\033[1mDebug:\033[0m\n{result.stderr.strip()}")
            break
        if result.stderr.strip() != "":
            print(f"\033[1mDebug:\033[0m\n{result.stderr.strip()}")

    print(test_case_delimiter)


if __name__ == "__main__":
    main()
