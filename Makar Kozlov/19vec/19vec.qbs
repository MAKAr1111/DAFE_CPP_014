import qbs

CppApplication {
    consoleApplication: true
    files:
        [
        "main.cpp",

        "Svector.h",
        //"Svector.cpp",

        "vector_base.h",

        "range_error.h",

        "readshow.h",
        //"readshow.cpp",

        "test.h",
        "test.cpp"
        ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
