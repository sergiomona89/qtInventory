
indent:
	find ./src -name '*.h' -exec astyle '{}' \;
	find ./src -name '*.cpp' -exec astyle '{}' \;
	find ./src -name '*.orig' -exec rm -rf '{}' \;

clean:
	find ./src -name '*~' -exec rm -rf '{}' \;

