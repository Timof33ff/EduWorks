import pandas as pd
from tabulate import tabulate
from faker import *
import random
import sqlite3

conn = sqlite3.connect("C:\\Qt\\KursovayaDB_Timofeev_K161B\\DB\\test\\BERUA_Of_TECH_INVENTORY.sqlite")
c = conn.cursor()

tables = {
    'Appartments':[],
    'Agreements':[],
    'Buildings':[],
    'BuildingOwners': [],
    'BuildingGroups': [],
    'Tenants':[],
    'Floors': [],
    'Entries' : []
}

str_columns = [] # columns with text data type

for i in tables.keys():
    c.execute(f'PRAGMA table_info({i})')
    column_names = [ i[1] for i in c.fetchall()]
    c.execute(f'PRAGMA table_info({i})')
    column_types = [ i[2] for i in c.fetchall()]   
    c.execute(f'PRAGMA table_info({i})')
    column_isPkey = [ i[5] for i in c.fetchall()]   
    for k, j, m in zip(column_names, column_types, column_isPkey):
        tables[i].append(tuple([k, j, m]))
        
        if j == 'TEXT':
            str_columns.append(k)

types = {'INTEGER' : int, 'REAL' : float, # helps to convert sql types to python types
                   'TEXT' : str, 'BLOB' : bool}

n : int = 50 # rows count
fake = Faker('ru_RU')

id = 0

for tab_name in tables.keys():
    conn.commit()
    list_of_values : list[tuple] = []
    questions = '?'
    c.execute("DELETE FROM " + tab_name)
    id = 0
    for _ in range(n):
        value_row : tuple = ()
        for col_tup in tables[tab_name]: # col_tup = (col_name, col_dtype)
            match col_tup[1]: # match column types
                case 'TEXT' : # match text 
                    if 'name' in col_tup[0]: value_row += (fake.name(), )
                    elif 'address' in col_tup[0]:  value_row += (fake.address(), )
                    elif 'street' in col_tup[0]:  value_row += (fake.street_name(), )
                    elif 'date' in col_tup[0]: value_row += (fake.date(), )
                    elif 'agreement' in col_tup[0]: value_row += (fake.bban(), )
                    elif 'purpose' in col_tup[0]: value_row += (random.choice(['Образование', 'Производство', 'Жилье', 'Медицина', 'Торговля']), )
                case 'BLOB' :
                    value_row += (random.choice([True, False]), )
                case 'REAL' : 
                    if 'square' == col_tup[0]: value_row += (round(random.uniform(20.0, 50.0), 3), )
                    elif 'all_square' == col_tup[0]: value_row += (round(random.uniform(200.0, 1000.0), 3), )
                    else : value_row += (round(random.uniform(200000.0, 500000.0), 3), )
                case 'INTEGER' :
                    if 'id' in col_tup[0] and col_tup[2] == 1:
                        value_row += (id, )
                        id += 1
                    elif 'id' in col_tup[0]: value_row += (random.randint(0, n), )
                    elif 'capacity' == col_tup[0]: value_row += (random.randint(100, 1000), )
                    elif 'share' == col_tup[0] : value_row += (random.choice([50, 100, 33, 25]), )
                    elif 'Etries' == tab_name and  'in_building_number' == col_tup[0] or 'room_count' == col_tup[0]: value_row += (random.randint(1, 5), )
                    elif 'Floors' == tab_name and  'in_building_number' == col_tup[0]: value_row += (random.randint(0, 20), )
                    else : value_row += (random.randint(0, 5), )
                case _ :
                    value_row += (random.randint(0, n), )

        list_of_values.append(value_row)
    print(tab_name)
    print(list_of_values)
    
    for _ in range(len(tables[tab_name])-1):
        questions+=', ?'
    print(questions)
    
    c.executemany(f'INSERT INTO {tab_name} VALUES ({questions})', list_of_values)

conn.commit()

