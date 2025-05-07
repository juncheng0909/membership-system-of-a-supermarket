# Supermarket Membership System

This is a simple C++ program that implements a membership system for a supermarket. It allows users to register, update information, make purchases, and check their transaction records.

## 🧩 Modules

### User
| Property  | Type          |
|-----------|---------------|
| name      | `string`      |
| birthday  | `string`      |
| records   | `vector<Record>` |

### Product
| Property  | Type     |
|-----------|----------|
| name      | `string` |
| price     | `int`    |
| count     | `int`    |

### Record
| Property  | Type             |
|-----------|------------------|
| date      | `string`         |
| products  | `vector<Product>` |

---

## 🔧 Operations

### 1. Register
Create a new user with name and birthday.

#### Input format:
```
register NAME BIRTHDAY
```

#### Example:
```
register User 1/23
```

---

### 2. Update
Update a user's birthday.

#### Input format:
```
update NAME BIRTHDAY
```

#### Example:
```
update User 3/21
```

---

### 3. Search
Search a user by name.

#### Input format:
```
search NAME
```

#### Output:
- If user exists: `NAME BIRTHDAY`
- If user doesn't exist: `USER NOT FOUND`

#### Example:
```
search User
```
Output:
```
User 3/21
```

---

### 4. Buy
Add a purchase record to a user.

#### Input format:
```
buy DATE NAME N
PRODUCT_NAME PRICE COUNT
...
```

#### Example:
```
buy 2345/6/7 User 3
Apple 12 3
Banana 45 6
Car 78 9
```

---

### 5. Check Detail
Show detail of a specific record.

#### Input format:
```
detail NAME RECORD_INDEX
```

#### Example:
```
detail User 0
```

#### Output:
```
2345/6/7 1008
Apple 12 3 36
Banana 45 6 270
Car 78 9 702
```

---

### 6. Check Summary
Show total consumption summary for a user.

#### Input format:
```
summary NAME
```

#### Example:
```
summary User
```

#### Output:
```
1 1008
```

---

## 📌 Note

- Arrays are implemented using `vector`.
- Input continues until EOF.
- No duplicated users or invalid queries will be tested.

---

## 🛠️ Language

- C++ (with `#include <vector>`, `#include <string>`, `#include <sstream>`)
