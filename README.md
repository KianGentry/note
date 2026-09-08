# note

A note management utility for the command line. Written in C++.

Notes are saved as "/tmp/note_name.txt". Every note begins with "note_", and is saved to /tmp/.

Can also be called by executing "n".

## Compile

Requirements:
- C++ Compiler for C++17 (g++)
- CMake (cmake)

```
cmake --build build
```

## Parameters

- [x] ls - Lists all notes
- [x] help - Prints help information
- [ ] grep [arg] || "arg" - Searches /tmp/ for notes based on query (note name or content)
- [ ] print [arg] - Prints note contents to terminal (most recent if no arg)
- [ ] append [arg] + "arg" - Appends content to specified note.
- [ ] config - Opens config file in default terminal text editor.
- [ ] rm [arg] - Deletes specified note.

All of the above can be called by doing -f, where f is the first letter of the parameter (e.g. note -l for note list).
Notes given no name default to note_2, where 1 the previous no-name note (for this example, note_1), plus 1.

Every instance of note name / note content is optional. It'll either default to a new note (with naming convention above), or open the most recent note, based on when its most appropriate to do either. No note content will open new / specified note in the default terminal text editor.

- [ ] [else] - Treat anything else as a name for new note, except...
- [ ] "else" - ...if it's in quotations. Write this to a new note as its contents. If this isn't specified, open new note in default terminal text editor (nano).

## Features

- [ ] Config file at ~/.config/noterc
- [ ] A configurable "timeout" period for notes (e.g. deleted after 1h).
- [ ] Configurable text editor to use.
