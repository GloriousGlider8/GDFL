extends Control

func _ready():
	var a = GDFLMii.new()
	var b = GDFLMii.new()
	var c = GDFLMii.new()
	a.from_ffsd(FileAccess.get_file_as_bytes("res://DFT_Cam.ffsd"))
	b.from_ffsd(FileAccess.get_file_as_bytes("res://DFT_Mirvi.ffsd"))
	c.from_ffsd(FileAccess.get_file_as_bytes("res://DFT_Sam.ffsd"))

	print("Names:")
	print(a.mii_name)
	print(b.mii_name)
	print(c.mii_name)

	print("Favourite Colors:")
	print(a.favorite_color)
	print(b.favorite_color)
	print(c.favorite_color)

	print("Is Favourite:")
	print(a.is_favorite)
	print(b.is_favorite)
	print(c.is_favorite)

	print("Genders:")
	print("Female" if a.is_female else "Male")
	print("Female" if b.is_female else "Male")
	print("Female" if c.is_female else "Male")

	print("Birthdays:")
	print(str(a.birth_day, "/", a.birth_month))
	print(str(a.birth_day, "/", a.birth_month))
	print(str(a.birth_day, "/", a.birth_month))
