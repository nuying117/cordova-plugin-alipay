Cordova 支付宝支付插件
======

## 最新更新

1. 增加callback
2. 默认使用自动安装的方法
3. 去除了对URL Scheme的依赖

## 支持的系统

* iOS
* Android

## 自动安装（Cordova > v5.1.1）

	cordova plugin add https://github.com/charleyw/cordova-plugin-alipay.git --variable PARTNER_ID=[你的商户PID可以在账户中查询] 

## 使用方法
```
window.alipay.pay( { order : "构建的订单参数串" }, 
                   function(successResults){alert(successResults)}, 
                   function(errorResults){alert(errorResults)} );
```
### 参数说明

* order 这个是根据支付宝文档(https://doc.open.alipay.com/doc2/detail?treeId=59&articleId=103927&docType=1)生成的参数串, 包含sign和sign_type, 本插件会将该串传给支付宝sdk
* function(successResults){} 是成功之后的回调函数
* function(errorResults){} 是失败之后的回调函数

`successResults`和`errorResults`分别是成功和失败之后支付宝SDK返回的结果，类似如下内容

```
// 成功
{
	resultStatus: "9000",
	memo: "",
	result: "partner=\"XXXX\"&seller_id=\"XXXX\"&out_trade_no=\"XXXXX\"..."	
}
```
```
// 用户取消
{
	memo: "用户中途取消", 
	resultStatus: "6001", 
	result: ""	
}
```

* resultStatus的含义请参照这个官方文档：[客户端返回码](https://doc.open.alipay.com/doc2/detail?treeId=59&articleId=103671&docType=1)
* memo：一般是一些纯中文的解释，出错的时候会有内容。
* result: 是所有支付请求参数的拼接起来的字符串。

## 手动安装
1. 使用git命令将插件下载到本地，并标记为$CORDOVA_PLUGIN_DIR

		git clone https://github.com/charleyw/cordova-plugin-alipay.git && cd cordova-plugin-alipay && export CORDOVA_PLUGIN_DIR=$(pwd)
		
2. 修改$CORDOVA_PLUGIN_DIR/plugin.xml，删除下面这一行：

		<preference name="PARTNER_ID"/>
		
2. 修改$CORDOVA_PLUGIN_DIR/plugin.xml，将

        <preference name="partner" value="$PARTNER_ID" />
改成

        <preference name="partner" value="<你的partner的id>" />

	**注意**：总共有两处
3. 安装

		cordova plugin add $CORDOVA_PLUGIN_DIR 


## Liscense

© 2015 Wang Chao, last changed by Wang Peng. This code is distributed under the MIT license.
