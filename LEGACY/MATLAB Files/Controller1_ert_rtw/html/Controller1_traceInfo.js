function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S1>/Constant */
	this.urlHashMap["starshotsimv4p3lqrproto:1175"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=starshotsimv4p3lqrproto:1175";
	/* <S1>/Cross Product */
	this.urlHashMap["starshotsimv4p3lqrproto:1123"] = "Controller1.h:130";
	/* <S1>/Cross Product2 */
	this.urlHashMap["starshotsimv4p3lqrproto:1125"] = "Controller1.h:131";
	/* <S1>/Gain */
	this.urlHashMap["starshotsimv4p3lqrproto:1170"] = "Controller1.cpp:49,59&Controller1.h:45&Controller1_data.cpp:26";
	/* <S1>/Saturation3 */
	this.urlHashMap["starshotsimv4p3lqrproto:1142"] = "Controller1.cpp:83,92";
	/* <S1>/Saturation4 */
	this.urlHashMap["starshotsimv4p3lqrproto:1143"] = "Controller1.cpp:61,70";
	/* <S1>/Saturation5 */
	this.urlHashMap["starshotsimv4p3lqrproto:1144"] = "Controller1.cpp:72,81";
	/* <S2>/Add3 */
	this.urlHashMap["starshotsimv4p3lqrproto:1123:22"] = "Controller1.cpp:39";
	/* <S2>/Element
product */
	this.urlHashMap["starshotsimv4p3lqrproto:1123:24"] = "Controller1.cpp:38";
	/* <S3>/Add3 */
	this.urlHashMap["starshotsimv4p3lqrproto:1125:22"] = "Controller1.cpp:97";
	/* <S3>/Element
product */
	this.urlHashMap["starshotsimv4p3lqrproto:1125:24"] = "Controller1.cpp:96";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Controller1"};
	this.sidHashMap["Controller1"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "starshotsimv4p3lqrproto:1120"};
	this.sidHashMap["starshotsimv4p3lqrproto:1120"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "starshotsimv4p3lqrproto:1123"};
	this.sidHashMap["starshotsimv4p3lqrproto:1123"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "starshotsimv4p3lqrproto:1125"};
	this.sidHashMap["starshotsimv4p3lqrproto:1125"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S1>/Angular Velocity"] = {sid: "starshotsimv4p3lqrproto:1121"};
	this.sidHashMap["starshotsimv4p3lqrproto:1121"] = {rtwname: "<S1>/Angular Velocity"};
	this.rtwnameHashMap["<S1>/Magnetic Field"] = {sid: "starshotsimv4p3lqrproto:1122"};
	this.sidHashMap["starshotsimv4p3lqrproto:1122"] = {rtwname: "<S1>/Magnetic Field"};
	this.rtwnameHashMap["<S1>/Constant"] = {sid: "starshotsimv4p3lqrproto:1175"};
	this.sidHashMap["starshotsimv4p3lqrproto:1175"] = {rtwname: "<S1>/Constant"};
	this.rtwnameHashMap["<S1>/Cross Product"] = {sid: "starshotsimv4p3lqrproto:1123"};
	this.sidHashMap["starshotsimv4p3lqrproto:1123"] = {rtwname: "<S1>/Cross Product"};
	this.rtwnameHashMap["<S1>/Cross Product2"] = {sid: "starshotsimv4p3lqrproto:1125"};
	this.sidHashMap["starshotsimv4p3lqrproto:1125"] = {rtwname: "<S1>/Cross Product2"};
	this.rtwnameHashMap["<S1>/Demux15"] = {sid: "starshotsimv4p3lqrproto:1126"};
	this.sidHashMap["starshotsimv4p3lqrproto:1126"] = {rtwname: "<S1>/Demux15"};
	this.rtwnameHashMap["<S1>/Gain"] = {sid: "starshotsimv4p3lqrproto:1170"};
	this.sidHashMap["starshotsimv4p3lqrproto:1170"] = {rtwname: "<S1>/Gain"};
	this.rtwnameHashMap["<S1>/Mux"] = {sid: "starshotsimv4p3lqrproto:1169"};
	this.sidHashMap["starshotsimv4p3lqrproto:1169"] = {rtwname: "<S1>/Mux"};
	this.rtwnameHashMap["<S1>/Mux2"] = {sid: "starshotsimv4p3lqrproto:1130"};
	this.sidHashMap["starshotsimv4p3lqrproto:1130"] = {rtwname: "<S1>/Mux2"};
	this.rtwnameHashMap["<S1>/Saturation3"] = {sid: "starshotsimv4p3lqrproto:1142"};
	this.sidHashMap["starshotsimv4p3lqrproto:1142"] = {rtwname: "<S1>/Saturation3"};
	this.rtwnameHashMap["<S1>/Saturation4"] = {sid: "starshotsimv4p3lqrproto:1143"};
	this.sidHashMap["starshotsimv4p3lqrproto:1143"] = {rtwname: "<S1>/Saturation4"};
	this.rtwnameHashMap["<S1>/Saturation5"] = {sid: "starshotsimv4p3lqrproto:1144"};
	this.sidHashMap["starshotsimv4p3lqrproto:1144"] = {rtwname: "<S1>/Saturation5"};
	this.rtwnameHashMap["<S1>/Out1"] = {sid: "starshotsimv4p3lqrproto:1148"};
	this.sidHashMap["starshotsimv4p3lqrproto:1148"] = {rtwname: "<S1>/Out1"};
	this.rtwnameHashMap["<S2>/a"] = {sid: "starshotsimv4p3lqrproto:1123:20"};
	this.sidHashMap["starshotsimv4p3lqrproto:1123:20"] = {rtwname: "<S2>/a"};
	this.rtwnameHashMap["<S2>/b"] = {sid: "starshotsimv4p3lqrproto:1123:21"};
	this.sidHashMap["starshotsimv4p3lqrproto:1123:21"] = {rtwname: "<S2>/b"};
	this.rtwnameHashMap["<S2>/Add3"] = {sid: "starshotsimv4p3lqrproto:1123:22"};
	this.sidHashMap["starshotsimv4p3lqrproto:1123:22"] = {rtwname: "<S2>/Add3"};
	this.rtwnameHashMap["<S2>/Demux2"] = {sid: "starshotsimv4p3lqrproto:1123:23"};
	this.sidHashMap["starshotsimv4p3lqrproto:1123:23"] = {rtwname: "<S2>/Demux2"};
	this.rtwnameHashMap["<S2>/Element product"] = {sid: "starshotsimv4p3lqrproto:1123:24"};
	this.sidHashMap["starshotsimv4p3lqrproto:1123:24"] = {rtwname: "<S2>/Element product"};
	this.rtwnameHashMap["<S2>/a elements"] = {sid: "starshotsimv4p3lqrproto:1123:25"};
	this.sidHashMap["starshotsimv4p3lqrproto:1123:25"] = {rtwname: "<S2>/a elements"};
	this.rtwnameHashMap["<S2>/b elements"] = {sid: "starshotsimv4p3lqrproto:1123:26"};
	this.sidHashMap["starshotsimv4p3lqrproto:1123:26"] = {rtwname: "<S2>/b elements"};
	this.rtwnameHashMap["<S2>/y"] = {sid: "starshotsimv4p3lqrproto:1123:27"};
	this.sidHashMap["starshotsimv4p3lqrproto:1123:27"] = {rtwname: "<S2>/y"};
	this.rtwnameHashMap["<S3>/a"] = {sid: "starshotsimv4p3lqrproto:1125:20"};
	this.sidHashMap["starshotsimv4p3lqrproto:1125:20"] = {rtwname: "<S3>/a"};
	this.rtwnameHashMap["<S3>/b"] = {sid: "starshotsimv4p3lqrproto:1125:21"};
	this.sidHashMap["starshotsimv4p3lqrproto:1125:21"] = {rtwname: "<S3>/b"};
	this.rtwnameHashMap["<S3>/Add3"] = {sid: "starshotsimv4p3lqrproto:1125:22"};
	this.sidHashMap["starshotsimv4p3lqrproto:1125:22"] = {rtwname: "<S3>/Add3"};
	this.rtwnameHashMap["<S3>/Demux2"] = {sid: "starshotsimv4p3lqrproto:1125:23"};
	this.sidHashMap["starshotsimv4p3lqrproto:1125:23"] = {rtwname: "<S3>/Demux2"};
	this.rtwnameHashMap["<S3>/Element product"] = {sid: "starshotsimv4p3lqrproto:1125:24"};
	this.sidHashMap["starshotsimv4p3lqrproto:1125:24"] = {rtwname: "<S3>/Element product"};
	this.rtwnameHashMap["<S3>/a elements"] = {sid: "starshotsimv4p3lqrproto:1125:25"};
	this.sidHashMap["starshotsimv4p3lqrproto:1125:25"] = {rtwname: "<S3>/a elements"};
	this.rtwnameHashMap["<S3>/b elements"] = {sid: "starshotsimv4p3lqrproto:1125:26"};
	this.sidHashMap["starshotsimv4p3lqrproto:1125:26"] = {rtwname: "<S3>/b elements"};
	this.rtwnameHashMap["<S3>/y"] = {sid: "starshotsimv4p3lqrproto:1125:27"};
	this.sidHashMap["starshotsimv4p3lqrproto:1125:27"] = {rtwname: "<S3>/y"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
