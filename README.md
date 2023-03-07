
# MINITALK 📡

This project is about to creating a ***communication program*** in the form of a client and a server. 

#### In this project I learned:
- working with **unix signals**;
- and doing **bitwise operations**;


## GRADE PROJECT ✅
- 125/100 📋
- [**Subject**](https://github.com/nunovaladao/42_Minitalk_lev2/blob/main/extras/en.subject.pdf) 

## RUN THE PROJECT:

#### 1 - Clone this repository
```bash
  git clone https://github.com/nunovaladao/42_Minitalk_lev2.git
```

#### 2 - Enter in the project folder and run `make`

```bash
  cd 42_Minitalk_lev2
  make
```
or *(if you want the bonus part - `make bonus`)*
```bash
  cd 42_Minitalk_lev2
  make bonus
```

#### 3 - Run the server 

```bash
  ./server
```

#### 4 - Run the client 
Now put the same pid between `./client` and the `message` you want to send 

```bash
  ./client <SERVER_PID> <message>
```
* Do the same with the ***bonus*** adding `_bonus` to the executables.

#### Makefile Rules

`make` or `make all` - Compile the **libft** and create **`./server`**  **`./client`** 

`make clean` - Remove all the **object files**

`make fclean` - Remove **executables** and the **object files**

`make bonus` - Compile the **libft** and create **`./server_bonus`**  **`./client_bonus`**

`make re` - use rules `fclean` + `all`

## Tests
You can use this test in your code:
- [francinette](https://github.com/xicodomingues/francinette) 

## Note:

[**Coding Norm**](https://github.com/nunovaladao/42_Minitalk_lev2/blob/main/extras/en_norm.pdf) - All students must follow the 42 code writing standards. This standard is applied to many projects in the course.
##
Nuno Valadão | nsoares-@student.42porto.com 


