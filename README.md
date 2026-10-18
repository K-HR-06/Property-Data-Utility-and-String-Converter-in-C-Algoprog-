# Property Data Utility and String Converter in C

Two command-line programs developed for the **Algorithm and Programming** course at **Bina Nusantara University**, Semester 1, 2023–2024.

The main program loads property records from a CSV file and provides a menu for displaying, searching, sorting, and exporting data. A separate program reverses an input string and switches the case of its letters.

This project demonstrates foundational C programming through structures, arrays, string manipulation, file handling, linear search, and comparison-based sorting.

## Repository Contents

| File | Description |
| --- | --- |
| `SoalAOL1.c` | String reversal and letter-case conversion program |
| `SoalAOL2.c` | Menu-driven property data utility |
| `file.csv` | Property dataset containing 3,939 records and eight columns |

## Technologies

- **C**
- Standard library headers: `stdio.h`, `string.h`, and `stdlib.h`
- CSV files for data input and export
- Command-line interface

## Property Data Utility

The program reads `file.csv` into an array of structures. Each structure stores one property record.

### Features

- **Display:** Print a user-specified number of rows.
- **Search:** Find all records matching an exact value in a selected column. Text matching is case-sensitive.
- **Sort:** Reorder records in memory and display the first 10 rows. Some sorting options have known defects, documented below.
- **Export:** Write the full dataset in its current in-memory order to a named CSV file.
- **Exit:** Close the program.

Search results do not replace the loaded dataset. Export therefore writes all loaded records, rather than only the results of the most recent search.

### Dataset

The supplied CSV contains **3,939 records**, all with `Kuala-Lumpur` in the second location column.

| CSV column | Program label | Stored as |
| --- | --- | --- |
| `Location 1` | `Location` | Text |
| `Location 2` | `City` | Text |
| `Price` | `Price` | Long long integer |
| `Rooms` | `Rooms` | Integer |
| `Bathrooms` | `Bathrooms` | Integer |
| `CarParks` | `CarParks` | Integer |
| `Type` | `Type` | Text |
| `Furnish` | `Furnish` | Text |

The assignment provides a dataset download link, but the supplied files do not establish the original data publisher, collection date, price currency, or reuse license.

## String Converter

`SoalAOL1.c` performs two operations:

1. Reverse the input string.
2. Convert uppercase ASCII letters to lowercase and lowercase ASCII letters to uppercase.

Example from the assignment, consistent with the source code:

```text
Input:
SuniBVerse

Expected output:
ESREvbINUs
```

The program reads one whitespace-delimited word. Its input buffer holds 100 characters, so input should be limited to 99 characters. This limit is not enforced by the code.

## Build and Run

Use a C compiler with C99 or later support. The following are example GCC commands; they have not been verified through a successful build in this review.

Compile each source file separately because each contains its own `main()` function:

```sh
gcc -std=c11 -Wall -Wextra SoalAOL1.c -o string_converter
gcc -std=c11 -Wall -Wextra SoalAOL2.c -o property_utility
```

On Linux or macOS:

```sh
./string_converter
./property_utility
```

On Windows with GCC, run the generated executables:

```powershell
.\string_converter.exe
.\property_utility.exe
```

Run the property utility from the directory containing `file.csv`; it uses a relative filename to open the dataset.

The exit option calls `system("cls")`, which is Windows-specific and may produce an error on other operating systems.

## Usage

The property utility displays this menu:

```text
What do you want to do?
1. Display data
2. Search data
3. Sort data
4. Export data
5. Exit
```

- To display records, choose `1` and enter a row count within the dataset size.
- To search, choose `2`, enter a column such as `Location`, then an exact value such as `Mont-Kiara`.
- To sort by price, choose `3`, enter `Price`, then `asc` or `des`.
- To export, choose `4` and enter a filename such as `property_export`. The program appends `.csv` automatically.

Search column names must match these labels exactly:

```text
Location
City
Price
Rooms
Bathrooms
CarParks
Type
Furnish
```

Export overwrites an existing file with the same name. Use a distinct output name to preserve the input dataset.

## Implementation Highlights

- Represents property records using an array of C structures.
- Parses CSV fields using formatted file input.
- Uses linear search to retrieve exact matches.
- Uses nested comparisons and structure swaps for sorting.
- Separates display, search, sort, export, and swap operations into functions.
- Uses loops and character comparisons for string conversion.

## Known Limitations

This repository preserves the submitted coursework implementation. Source inspection identifies the following issues:

- **Sorting defects:** Descending `Location` sorting compares city values instead of locations. An always-true condition routes all column choices other than `Location`, `Price`, and `Rooms` into bathroom sorting, making later sorting branches unreachable. Both bathroom sort directions use the ascending comparison.
- **Display bounds:** The requested row count is not checked against the number of loaded records.
- **Input and CSV validation:** String reads have no width limits, CSV parsing results are not checked, and the fixed array has capacity for 3,941 records without a loading bounds check. Quoted CSV fields containing commas are not supported.
- **Price search:** Prices are stored as `long long`, but the search value is read as `int`, limiting the supported search range.
- **Export handling:** The program does not check whether the output file opened successfully.
- **Scalability:** The nested-loop sorting approach has quadratic time complexity.

## Verification Status

The source code, assignment document, and supplied dataset were inspected. Compilation and runtime behavior remain unverified because the local GCC executable failed to start during review.

No automated tests, benchmark results, or software license were included in the supplied archive.
