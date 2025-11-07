extends Control

func _ready():
	var a = preload("res://DFT_Cam.ffsd")
	var b = preload("res://DFT_Mirvi.ffsd")
	var c = preload("res://DFT_Sam.ffsd")
	var d = preload("res://testmii.ffsd")

	print("Names:")
	print(a.name)
	print(b.name)
	print(c.name)
	print(d.name)

	print("Favourite Colors:")
	print(a.favorite_color)
	print(b.favorite_color)
	print(c.favorite_color)
	print(d.favorite_color)

	print("Is Favourite:")
	print(a.favorite)
	print(b.favorite)
	print(c.favorite)
	print(d.favorite)

	print("Genders:")
	print(a.gender)
	print(b.gender)
	print(c.gender)
	print(d.gender)

	print("Birthdays:")
	print(str(a.birth_day, "/", a.birth_month))
	print(str(a.birth_day, "/", a.birth_month))
	print(str(a.birth_day, "/", a.birth_month))
	print(str(d.birth_day, "/", a.birth_month))
