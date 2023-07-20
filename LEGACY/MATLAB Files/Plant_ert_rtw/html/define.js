function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:39,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:76,type:"fcn"};
this.def["rtX"] = {file: "Plant_c.html",line:43,type:"var"};
this.def["rtDW"] = {file: "Plant_c.html",line:46,type:"var"};
this.def["rtU"] = {file: "Plant_c.html",line:49,type:"var"};
this.def["rtY"] = {file: "Plant_c.html",line:52,type:"var"};
this.def["rtM_"] = {file: "Plant_c.html",line:55,type:"var"};
this.def["rtM"] = {file: "Plant_c.html",line:56,type:"var"};
this.def["BigEndianIEEEDouble"] = {file: "Plant_c.html",line:110,type:"type"};
this.def["LittleEndianIEEEDouble"] = {file: "Plant_c.html",line:117,type:"type"};
this.def["IEEESingle"] = {file: "Plant_c.html",line:124,type:"type"};
this.def["rtInf"] = {file: "Plant_c.html",line:126,type:"var"};
this.def["rtMinusInf"] = {file: "Plant_c.html",line:127,type:"var"};
this.def["rtNaN"] = {file: "Plant_c.html",line:128,type:"var"};
this.def["rtInfF"] = {file: "Plant_c.html",line:129,type:"var"};
this.def["rtMinusInfF"] = {file: "Plant_c.html",line:130,type:"var"};
this.def["rtNaNF"] = {file: "Plant_c.html",line:131,type:"var"};
this.def["rtGetNaN"] = {file: "Plant_c.html",line:141,type:"fcn"};
this.def["rtGetNaNF"] = {file: "Plant_c.html",line:165,type:"fcn"};
this.def["rt_InitInfAndNaN"] = {file: "Plant_c.html",line:177,type:"fcn"};
this.def["rtIsInf"] = {file: "Plant_c.html",line:189,type:"fcn"};
this.def["rtIsInfF"] = {file: "Plant_c.html",line:195,type:"fcn"};
this.def["rtIsNaN"] = {file: "Plant_c.html",line:201,type:"fcn"};
this.def["rtIsNaNF"] = {file: "Plant_c.html",line:207,type:"fcn"};
this.def["rtGetInf"] = {file: "Plant_c.html",line:216,type:"fcn"};
this.def["rtGetInfF"] = {file: "Plant_c.html",line:240,type:"fcn"};
this.def["rtGetMinusInf"] = {file: "Plant_c.html",line:251,type:"fcn"};
this.def["rtGetMinusInfF"] = {file: "Plant_c.html",line:275,type:"fcn"};
this.def["rt_ertODEUpdateContinuousStates"] = {file: "Plant_c.html",line:286,type:"fcn"};
this.def["rt_atan2d_snf"] = {file: "Plant_c.html",line:417,type:"fcn"};
this.def["Plant_step"] = {file: "Plant_c.html",line:454,type:"fcn"};
this.def["Plant_derivatives"] = {file: "Plant_c.html",line:839,type:"fcn"};
this.def["Plant_initialize"] = {file: "Plant_c.html",line:885,type:"fcn"};
this.def["RT_MODEL"] = {file: "Plant_h.html",line:60,type:"type"};
this.def["DW"] = {file: "Plant_h.html",line:75,type:"type"};
this.def["X"] = {file: "Plant_h.html",line:89,type:"type"};
this.def["XDot"] = {file: "Plant_h.html",line:103,type:"type"};
this.def["XDis"] = {file: "Plant_h.html",line:117,type:"type"};
this.def["ODE5_IntgData"] = {file: "Plant_h.html",line:126,type:"type"};
this.def["ConstP"] = {file: "Plant_h.html",line:146,type:"type"};
this.def["ExtU"] = {file: "Plant_h.html",line:151,type:"type"};
this.def["ExtY"] = {file: "Plant_h.html",line:157,type:"type"};
this.def["rtConstP"] = {file: "Plant_data_c.html",line:25,type:"var"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:59,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:60,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:71,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:72,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:73,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:74,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:92,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["Plant_c.html"] = "../Plant.c";
	this.html2Root["Plant_c.html"] = "Plant_c.html";
	this.html2SrcPath["Plant_h.html"] = "../Plant.h";
	this.html2Root["Plant_h.html"] = "Plant_h.html";
	this.html2SrcPath["Plant_data_c.html"] = "../Plant_data.c";
	this.html2Root["Plant_data_c.html"] = "Plant_data_c.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","Plant_c.html","Plant_h.html","Plant_data_c.html","rtwtypes_h.html"];
