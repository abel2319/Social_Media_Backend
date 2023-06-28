std::string serializeMap(const std::map<std::string, std::string>& data) {
	json j(data);
	return j.dump();
}

std::map<std::string, std::string> deserializeMap(const std::string& serializedMapData) {
    std::map<std::string, std::string> deserializedMap;
    try {
        json j = json::parse(serializedMapData);
        deserializedMap = j.get<std::map<std::string, std::string>>();
    } catch (const json::exception& e) {
        cout<<"deserialization error\n";
    }
    return deserializedMap;
}
