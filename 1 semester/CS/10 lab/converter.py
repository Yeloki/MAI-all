from pprint import pprint

with open('main.log', encoding='cp1252') as file:
    data = file.readlines()


pprint(data)