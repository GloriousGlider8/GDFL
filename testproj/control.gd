extends Control

func _ready():
	var a = GDFLMii.new()
	var b = GDFLMii.new()
	var c = GDFLMii.new()
	a.from_ffsd(FileAccess.get_file_as_bytes("res://CPU_Displayette.ffsd"))
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

	print("Gender:")
	print("Female" if a.is_male else "Male")
	print("Female" if b.is_male else "Male")
	print("Female" if c.is_male else "Male")
