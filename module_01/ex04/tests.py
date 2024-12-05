import os

# Directory to hold the test files
test_dir = "./testsss"
os.makedirs(test_dir, exist_ok=True)

# Test files and content
test_files = {
    "test1": "This is a simple test.\nThis test should pass.",
    "test1.replace": "This is a complex test.\nThis test should pass.",
    "test2": "Replace every apple with an orange.\nApples are red, but oranges are orange.",
    "test2.replace": "Replace every orange with an orange.\nOranges are red, but oranges are orange.",
    "test3": "The quick brown fox\njumps over the lazy dog.",
    "test3.replace": "The quick red fox\njumps over the lazy cat.",
    "test4": "Coding in C++ can be fun.\nSometimes it can also be frustrating.",
    "test4.replace": "Programming in Python can be fun.\nSometimes it can also be frustrating.",
    "test5": "Rainy days often feel gloomy.\nI prefer the sunshine.",
    "test5.replace": "Sunny days often feel cheerful.\nI prefer the sunshine.",
    "test6": "Books are a great source of knowledge.\nThey can also inspire creativity.",
    "test6.replace": "Libraries are a great source of knowledge.\nThey can also inspire creativity.",
    "test7": "Artificial intelligence\nis transforming industries worldwide.",
    "test7.replace": "Machine learning\nis transforming industries worldwide.",
    "test8": "Open-source software encourages collaboration.\nIt drives innovation across the tech world.",
    "test8.replace": "Free software encourages collaboration.\nIt drives innovation across the tech world.",
    "test9": "Astronomy helps us understand the universe.\nIt reveals the mysteries of space.",
    "test9.replace": "Astrophysics helps us understand the universe.\nIt reveals the mysteries of space.",
    "test10": "This is a placeholder text.\nIt is used for testing purposes.",
    "test10.replace": "This is an example text.\nIt is used for testing purposes.",
}

# Args file content
args_content = """\
test1->simple
test1->complex
test2->apple
test2->orange
test3->brown
test3->red
test3->dog
test3->cat
test4->Coding
test4->Programming
test4->C++
test4->Python
test5->Rainy
test5->Sunny
test5->gloomy
test5->cheerful
test6->Books
test6->Libraries
test7->Artificial intelligence
test7->Machine learning
test8->Open-source
test8->Free
test9->Astronomy
test9->Astrophysics
test10->placeholder
test10->example
"""

# Create test files
for filename, content in test_files.items():
    with open(os.path.join(test_dir, filename), 'w') as f:
        f.write(content)

# Create args file
with open(os.path.join(test_dir, "args"), 'w') as f:
    f.write(args_content)

test_dir