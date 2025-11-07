@tool
extends EditorImportPlugin

func _get_importer_name():
	return "gdfl.v3storedata"

func _get_visible_name():
	return "Version 3 Store Data"

func _get_recognized_extensions():
	return ["ffsd", "cfsd", "3dsmii"]

func _get_save_extension():
	return "res"

func _get_resource_type():
	return "Mii"

func _get_preset_count():
	return 0

func _get_preset_name(p):
	return ""

func _get_import_options(p, pi):
	return []

func _get_option_visibility(path, option_name, options):
	return false

func _import(source_file, save_path, options, r_platform_variants, r_gen_files):
	var file = FileAccess.open(source_file, FileAccess.READ)
	if file == null:
		return FileAccess.get_open_error()

	var m: Mii = Mii.from_v3(file.get_buffer(file.get_length()))

	return ResourceSaver.save(m, "%s.%s" % [save_path, _get_save_extension()])
