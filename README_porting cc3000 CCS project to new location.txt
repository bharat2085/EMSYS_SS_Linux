You will need to follow following steps to shift/port cc3000 CCS project to new location.

1. Copy whole project directory ( folder containing CCS && Source folders) to new location.
2. Switch Workspace to new location(   new_location/CCS/Workspace).
3. Now you can delete or rename old directory if you wish to .( Note that: CCStudio keep locking the current Workspace directory)
4. Delete all the existing projects, bcoz they point to old location. Project--> Import all CCS projects from new location.(dont copy projects into workspace).
<5. HostDriver may have  included absolute addr of  Source/Application/inc folder.(which need to be changed in settings CCStudio-Project properties>Compiler->include).di> this is problem only in cc3000_applicatons_original_base_work , its not a problem for all  project_backups newer than 16_02_2015.
6. If you have not changed the whole project directory, copied as it is from original project directory location. then you are done!!
7  If you have changed , then links of source file will not work and you will need to import each file again,may need to change link of include and library directory.

just like dat.