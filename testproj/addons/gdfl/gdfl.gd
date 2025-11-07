@tool
extends EditorPlugin

var ffsd_import
var ffra_import

func _enter_tree():
	ffsd_import = preload("ffsd_import.gd").new()
	ffra_import = preload("ffra_import.gd").new()
	add_import_plugin(ffsd_import)
	add_import_plugin(ffra_import)

func _exit_tree():
	remove_import_plugin(ffsd_import)
	remove_import_plugin(ffra_import)
	ffsd_import = null
	ffra_import = null
