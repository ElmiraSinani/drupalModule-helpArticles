
services_help_articles module allows get nodes by custom field value (field_cobol)  using Services module

How to use:

1. Create new content type help_articles 

2. Add new field for help_articles content type by name cobol
	
3.	Enable module Help Articles

	Modules->Services and enable module  Help Articles 
	
4.  Add new endpoint by name services. If you already have services endpoint go to 3-rd step

	Structure->Servises->Add	
	Machine-readable name of the endpoint -> services
	Server -> REST
	Path to endpoint -> services
		enable Session authentication 
		-> SAVE

5.  Edit Resources for services
	
	enable help -> save
	
5.  http://<host_name>/services/help/<cobol_value>
	
	<host_name> -> type here your host name
	<cobol_value> -> machine readable name (or value of field_cobol) of cobol field
	
	for json output:
		http://<host_name>/services/term/<cobol_value>.json)
	
	