extends Control

func _ready():
	print("a")
	var a = GDFLMii.new()
	a.from_ffsd(FileAccess.get_file_as_bytes("res://CPU_Displayette.ffsd"))
	print("FFSD Loaded!")
	print(a.mii_name)
	print("if that said display GB then FUCK YES WE FINALLY BEAT THE GD-KAITAI BARRIER!	")
