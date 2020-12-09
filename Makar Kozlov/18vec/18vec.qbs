import qbs

CppApplication {
    consoleApplication: true
    files:
        [
        "main.cpp",

        "vector.h",
        "vector.cpp",

        "readshow.h",
        "readshow.cpp",

        "test.h",
        "test.cpp"
        ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
