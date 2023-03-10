# 大作业：金山待办软件



## 一、背景

仿照金山待办的部分功能，使用 Qt 在本地搭建数据库实现了离线的Todo-List

## 二、实现功能

以下需求功能在作业中均得到了实现。

### 1. 我的首页

- 主要包含三个部分:

- - 新建待办项目 

  - - 点击新建待办项目后将提示框转变为输入框，输入待办事件后点击回车完成新建待办操作。新建待办后可以进一步进行设置。

- - 展示所有待办项目

  - - 在右侧的展示页面展示出所有的待办事件，已经完成的待办事件不显示。待办事件按到期时间可分为如下三大类：

    - - 未安排
      - 未来7天
      - 以后(大于7天)

- - 刷新

  - - 点击刷新按钮更新当前页面的待办事件与分类信息。

### 2. 我的待办

- 展示所有待办项目

- - 在右侧的展示页面展示出所有的用户本人创建的待办事件，不进行分类，但是可以进行排序。已经完成的待办事件折叠起来。

- 刷新

- - 点击刷新按钮更新当前页面的待办事件与分类信息。

- 排序

- - 点击下拉框选择排序方式对所有待办事件进行排序，排序方式分如下几类：

  - - 按到期时间排序
    - 按创建时间排序
    - 按优先级排序

- 新建待办项目

- - 点击新建待办项目后将提示框转变为输入框，输入待办事件后点击回车完成新建待办操作。新建待办后可以进一步进行设置，详细设置请参考下方系统功能“待办事件”。

### 3. 分组

-  新建分组

- - 点击左侧添加分组按钮可以新建一个分组，创建后可以邀请其他人加入分组

- 新建待办项目

- - 点击新建待办项目后将提示框转变为输入框，输入待办事件后点击回车完成新建待办操作。新建待办后可以进一步进行设置，详细设置请参考下方系统功能“待办事件”。

- 展示分组中的待办项目

- - 点击分组后右侧会展示分组中的待办项目。已经完成的待办事件折叠起来。

- 刷新

- - 点击刷新按钮更新当前页面的待办事件与分类信息。

- 排序

- - 点击下拉框选择排序方式对所有待办事件进行排序，排序方式分如下几类

  - 1. 按到期时间排序；

  - 2. 按创建时间排序；

  - 3. 按优先级排序；

### 4. 待办事件

- 是否完成该事件

- - 每个待办事件前有一个勾选框，用来判断是否已经完成该事件，点击勾选框后会在待办事件中清除该事件，并放置于“我的待办”页面中的“已完成”分类下，已完成分类默认是折叠的。

- 展示待办事件的详细信息

- - 在待办事情前显示待办事件的优先级：

  - - 优先级 无（不显示）
    - 优先级 高
    - 优先级 中
    - 优先级 低

  - 在 待办事件下方简要显示待办事件的如下信息:

  - - 到期时间
    - 是否重复
    - 提醒时间
    - 组别时间

- 进一步设置待办事件的详细信息

- - 点击待办事件后进一步设置待办事件的详细信息

  - - 优先级
    - 到期时间
    - 提醒时间
    - 添加描述
    - 添加地点
    - 添加备注