extends Control

func _ready():
	var a = GDFLBasicTestClass.new()
	a.test_func()
	var m = GDFLMii.new()
	print("a")
	m.from_ffsd(PackedByteArray([]))
