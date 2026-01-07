# get next line

This project has been created as part of the 42 curriculum by tphuwian.

This comprehensive summary is designed for your project documentation, combining your specific code implementation with the theoretical requirements of the subject.

---

<!-- ## ## 1. Project Description -->

**Goal:**
The primary objective of this project is to create a function that returns a single line from a **File Descriptor (fd)** each time it is called. A "line" is defined as a string ending with a newline character (`\n`) or the End Of File (EOF).

**Overview:**
In professional software development and embedded systems, data is often received in streams rather than all at once. This project simulates that environment by using a **static variable** (`static char *stash`) to persist data across multiple function calls. This allows the function to "remember" any leftover data that was read but not yet returned as a complete line.

---

<!-- ## ## 2. System Functions: Deep Dive -->

To interface with the file system, the project utilizes two essential Unix system calls: `open()` and `read()`.

### **A. `open()` Function**

Before reading, the system must establish a connection to the file.

* **Library Requirement:** `#include <fcntl.h>`.
* **Prototype:** `int open (const char* path, int flags [, int mode ]);`.
* **Return Type:** `int`.
* **Success:** A file descriptor (a small, nonnegative integer) used as an index in the process's file table.
* **Failure:** Returns `-1`.


* **Parameters:**
* `path` (**Type: `const char ***`): The title or location of the file (e.g., `"test.txt"` or `/Users/name/file`).
* `flags` (**Type: `int**`): Defines access mode. Common flags include `O_RDONLY` (Read-only), `O_WRONLY` (Write-only), and `O_CREAT` (Create if missing).



### **B. `read()` Function**

This function transfers data from the file into the program's memory.

* **Prototype:** `ssize_t read(int fildes, void *buf, size_t nbyte);`.
* **Return Type:** `ssize_t` (signed size type).
* **Value > 0**: Represents the actual number of bytes read into the buffer.
* **Value == 0**: Indicates the end of the file (EOF).
* **Value == -1**: Indicates a failure/error during reading.


* **Parameters:**
* `fildes` (**Type: `int**`): The file descriptor obtained from `open()`.
* `buf` (**Type: `void ***`): A pointer to the buffer (in your code, the `box` variable) where data will be stored.
* `nbyte` (**Type: `size_t**`): The number of bytes to attempt to read (your `BUFFER_SIZE`).



---

<!-- ## ## 3. Algorithm Explanation & Justification -->

**Selected Algorithm: "Incremental Buffer Concatenation & Remainder Management"**

1. **Read and Accumulate (`read_stash`):**
* The function reads `BUFFER_SIZE` bytes into a temporary `box`.
* It uses `ft_strjoin` to append this new data to the existing `stash` until a `\n` is detected by `find_ad_nl`.
* **Justification:** Reading in chunks (instead of character by character) significantly reduces the overhead of repeated system calls, improving performance.


2. **Extract the Result (`extract_nl`):**
* Once `stash` contains a full line, `extract_nl` calculates the exact length needed (including `\n`) and uses `malloc` to create the final string.
* **Justification:** Explicitly calculating length + 1 ensures sufficient space for the Null-terminator (`\0`), preventing memory corruption.


3. **Update the State (`clear_stash`):**
* The `stash` is updated to keep only the data that follows the `\n`.
* **Justification:** Using a `static` pointer to the "remainder" ensures that no data is lost between calls, maintaining a continuous stream.



---

<!-- ## ## 4. Instructions -->

### **Compilation**

You must define the `BUFFER_SIZE` macro at compile-time:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

```

### **Usage**

Open a file using `open()`, then pass the resulting file descriptor to `get_next_line(fd)`. Ensure you `free()` the pointer returned by the function to avoid memory leaks.

---
<!-- 
## ## 5. Resources & AI Usage -->

* **Unix Manual Pages**: Documentation for `read(2)`, `open(2)`, and `malloc(3)`.
* **AI Usage Disclosure**: Gemini was used as a technical partner for:
* **Logic Debugging**: Resolving **Double Free** errors in `read_stash` by properly handling `n < 0` cases.
* **Refactoring**: Designing the `for_free` utility to manage multiple pointer deallocations efficiently within the Norminette constraints.
* **Theoretical Summarization**: Clarifying the relationship between file descriptors, offsets, and heap memory management for evaluation readiness.

# This readme is create by GEMINI.