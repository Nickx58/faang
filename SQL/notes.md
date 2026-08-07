# SQL Notes

---

# SQL Basics

## SELECT

Used to retrieve data from one or more columns from a table.

### Syntax

```sql
SELECT column_name
FROM table_name;
```

### Examples

Select all columns

```sql
SELECT *
FROM books;
```

Select specific columns

```sql
SELECT title, author
FROM books;
```

### Notes

- `*` selects all columns.
- Use specific column names instead of `*` in production for better readability and performance.

---

## FROM

Specifies the table from which data should be retrieved.

### Syntax

```sql
SELECT column_name
FROM table_name;
```

### Example

```sql
SELECT title
FROM books;
```

Here, `books` is the table from which SQL fetches the data.

### Notes

- Every `SELECT` statement needs a `FROM` clause (unless selecting constants).
- The `FROM` clause tells SQL where the data exists.

---

## DISTINCT

Returns only unique values by removing duplicates.

### Syntax

```sql
SELECT DISTINCT column_name
FROM table_name;
```

### Example

```sql
SELECT DISTINCT year_hired
FROM employees;
```

### Example Output

Without `DISTINCT`

```
2020
2020
2021
2022
2022
```

With `DISTINCT`

```
2020
2021
2022
```

### Notes

- Removes duplicate values.
- Can be used on one or multiple columns.
- Does not modify the data in the table; it only changes the query result.

---

# Summary

| Keyword  | Purpose                    |
| -------- | -------------------------- |
| SELECT   | Retrieve data from a table |
| FROM     | Specify the table to query |
| DISTINCT | Return only unique values  |
