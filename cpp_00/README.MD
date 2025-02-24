
Write a program that works as a phonebook:

Two classes:

- PhoneBook:
- Array of contacts
- Maximum of 8 contacts. Trying t add a 9th one, it will replace the oldest one.
- Dynamic allocation is forbidden.

- Contact:
- Fields:
- First name
- Last name
- Nickname
- Phone number
- Darkest secret
- A contact cant have empty fields

Program commands:

- ADD:prompts input for contact info one field at a time.
- SEARCH:
- Display contact list:
- 4 columns (index, first name, last name, nickname)
	- Each column 10 char wide, separated by '|'. 
	If the text > 10 char it must be truncated and last char must be replaced by '.'
	- Then prompt input for contact selection by index:
	- Wrong (> 9): relevant behaviour
				   - Right (< 9): display contact info one field per line
								  - EXIT: program quits and contacts deleted.

											  * Discard wrong commands
